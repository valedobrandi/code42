#include "cub3d.h"
#include <mlx.h>
#include <math.h>


static void ray_draw(int x, int y, t_settings *st, unsigned int color)
{
    int offset = y * st->addr.line_len + x * (st->addr.bpp / 8);
    *(unsigned int *)(st->img_data + offset) = color;
}

void render3d(t_settings **st)
{
    int i = 0;
    int screen_width = 800;   // Adjust
    int screen_height = 600;  // Adjust

    double max_distance = 15.0;

    while (i < screen_width)
    {
        double step = 0.0;

        double angle_offset = ((double)i / (double)screen_width - 0.5) * FFOV;
        double ray_angle = (*st)->player.pa + angle_offset;

        double ray_dx = cos(ray_angle);
        double ray_dy = sin(ray_angle);

        while (step < max_distance)
        {
            double ray_x = (*st)->player.px + ray_dx * step;
            double ray_y = (*st)->player.py + ray_dy * step;
            if ((*st)->scheme->map[(int)ray_y].path[(int)ray_x] == '1')
                break ;
            step += 0.01;
        }

		int tex_height = 480;
		int tex_width = 480;

		// The X Y exact point of impact
		double hit_x = (*st)->player.px + ray_dx * step;
		double hit_y = (*st)->player.py + ray_dy * step;

		// Convert to (0.0 ~ 1.0) for horizontal and vertical
		double wall_x;

		if (fabs(ray_dx) > fabs(ray_dy))
			wall_x = hit_y - floor(hit_y);
		else
			wall_x = hit_x - floor(hit_x);

		int tex_x = (int)(wall_x * tex_width);

        double wall_distance = step * cos(angle_offset);

        double wall_heigth = (screen_height / wall_distance) * 0.5;

        int wall_start = (screen_height / 2) - ((int)wall_heigth / 2);
        int wall_end = (screen_height / 2) + ((int)wall_heigth / 2);

        if (wall_start < 0) wall_start = 0;
        if (wall_end >= screen_height) wall_end = screen_height - 1;

		// how much to increase texture y per screnn pixel
		double tex_step = (double)tex_height / (double)(wall_end - wall_start);
		// texture position y start
		double tex_pos = 0.0;

		if (wall_start == 0 && (screen_height / 2) - (wall_heigth / 2) < 0) {
			double clipped_pixels = -((screen_height / 2) - (wall_heigth / 2));
			tex_pos = clipped_pixels * tex_step;
		}

        int y = 0;
        while (y < screen_height)
        {
            unsigned int color;

            if (y < wall_start)
                color = 0x436775; // Sky color
            else if (y >= wall_start && y <= wall_end)
			{
				// wrap around texture size x render size
				int tex_y = (int)tex_pos;
				if (tex_x < 0) tex_x = 0;
				if (tex_x >= tex_width) tex_x = tex_width - 1;
                if (tex_y < 0) tex_y = 0;
				if (tex_y >= tex_height) tex_y = tex_height - 1;

				tex_pos += tex_step;

				char *data = (*st)->mlx_texture.south_wall;
				int offset = tex_y * (*st)->addr.line_len + tex_x * ((*st)->addr.bpp / 8);
				int max_offset = tex_height * (*st)->addr.line_len;

				if (offset < 0 || offset >= max_offset - 4) {
					color = 0xFF00FF;  // error color
				} else {
					color = *(unsigned int *)(data + offset);
				}

			}
            else
                color = 0x228B22;

            ray_draw(i, y, *st, color);
            y++;
        }
        i++;
    }
}

/* t_dda_result cast_dda_ray(t_settings *st, double ray_angle)
{
	t_dda_result result = {0, 0, 0, 0};

	//ray direction
	double ray_dx = cos(ray_angle);
	double ray_dy = sin(ray_angle);

	//start position
	double ray_x = st->player.px;
	double ray_y = st->player.py;

	//get grid position we're in
	int map_x = (int)ray_x;
	int map_y = (int)ray_y;

	//ray length from current position to next x or y
	double side_dist_x, side_dist_y;

	//ray length fro; one grid crossing to next
	double delta_dist_x = (ray_dx == 0) ? 1e30 : fabs(1.0 / ray_dx);
	double delta_dist_y = (ray_dy == 0) ? 1e30 : fabs(1.0 / ray_dy);

	//ste direction and initial side distance
	int step_x, step_y;
	if (ray_dx < 0)
	{
		step_x = -1;
		side_dist_x = (ray_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (ray_x - map_x) * delta_dist_x;
	}
	if (ray_dy < 0)
	{
		step_y = -1;
		side_dist_y = (ray_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (ray_y - map_y) * delta_dist_y;
	}

	//perform DDA
	int hit = 0;
	int side; //0 for vertical wall, 1 for horizontal wall

	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		//check out of bound map
		if (map_x < 0 || map_y < 0 || map_x > st->scheme->map[map_y].length || map_y > st->scheme->height) {
			break;
		}

		if (st->scheme->map[map_y].path[map_x] == '1')
		{
			hit = 1;
		}
	}

	if (hit)
	{
		//calculate perpendicular distance for fisheye effect
		double perp_wal_dist;
		if (side == 0)
			perp_wal_dist = (map_x - ray_x + (1 - step_x) / 2) / ray_dx;
		else
			perp_wal_dist = (map_y - ray_y + (1 - step_y) / 2) / ray_dy;

		//calculate wall_x for texture mapping
		double wall_x;
		if (side == 0)
			wall_x = ray_y + perp_wal_dist * ray_dy;
		else
			wall_x = ray_x + perp_wal_dist * ray_dx;

		wall_x = wall_x - floor(wall_x);

		result.distance = perp_wal_dist;
		result.hit_wall = 1;
		result.wall_side = side;
		result.wall_x = wall_x;
	}

	return (result);
}
void render3d(t_settings **st)
{
    int i = 0;
    int screen_width = 800;   // Adjust
    int screen_height = 600;  // Adjust

    while (i < screen_width)
    {

        double angle_offset = ((double)i / (double)screen_width - 0.5) * FFOV;
        double ray_angle = (*st)->player.pa + angle_offset;

        t_dda_result ray = cast_dda_ray(*st, ray_angle);

		if (!ray.hit_wall)
		{
			int y = 0;
			while (y < screen_height)
			{
				unsigned int color = (y < screen_height / 2) ? 0x436775 : 0x228B22;
				ray_draw(i, y, *st, color);
				y++;
			}
			i++;
			continue;
		}

		int tex_height = 480;
		int tex_width = 480;

        double wall_distance = ray.distance * cos(angle_offset);

        double wall_heigth = (screen_height / wall_distance) * 0.5;

        int wall_start = (screen_height / 2) - (wall_heigth / 2);
        int wall_end = (screen_height / 2) + (wall_heigth / 2);

        if (wall_start < 0) wall_start = 0;
        if (wall_end >= screen_height) wall_end = screen_height - 1;

		//calculate texture X cordinate
		int tex_x = (int)(ray.wall_x * tex_width);

		//flip texture for proper orientation
		if ((ray.wall_side == 0 && cos(ray_angle) > 0)
			|| (ray.wall_side == 1 && cos(ray_angle) < 0))
		{
			tex_x = tex_width - tex_x - 1;
		}

		//Ensure tex_x is within bounds
		if (tex_x < 0) tex_x = 0;
		if (tex_x >= tex_width) tex_x =  tex_width - 1;

		//texture step calculation
		double tex_step = (double)tex_height / (double)(wall_end - wall_start);
		double tex_pos = 0.0;

		// If wall extends above screen, start texture from appropriate position
		if (wall_start == 0 && (screen_height / 2) - (wall_heigth / 2) < 0) {
            double clipped_pixels = -((screen_height / 2) - (wall_heigth / 2));
            tex_pos = clipped_pixels * tex_step;
        }

        int y = 0;
        while (y < screen_height)
        {
            unsigned int color;

            if (y < wall_start)
                color = 0x436775; // Sky color
            else if (y >= wall_start && y <= wall_end)
			{
				//wall texture
				int tex_y = (int)tex_pos;

				// Ensure tex_y is within bounds
                if (tex_y < 0) tex_y = 0;
                if (tex_y >= tex_height) tex_y = tex_height - 1;

				tex_pos += tex_step;

				char *data = (*st)->mlx_texture.north_wall;
				int offset = tex_y * (*st)->addr.line_len + tex_x * ((*st)->addr.bpp / 8);

				int max_offset = tex_height * (*st)->addr.line_len;
				//-4 for 32-bit color safety
                if (offset >= 0 && offset < max_offset - 4)
                    color = *(unsigned int *)(data + offset);
				else
					color = 0xFF00FF;
			}
            else
                color = 0x228B22;

            ray_draw(i, y, *st, color);
            y++;
        }
        i++;
    }
} */
/* void	drawrays3d(t_settings *st)
{
	double	step;
	double	max_distance;
	double	ray_x;
	double	ray_y;


	max_distance = 15.0;
    int i = 0;
    while (i < 60)
    {
	    step = 0.0;

        double angle_offset = (i / 59.0) * FFOV - HFOV;
        double ray_angle = st->player.pa + angle_offset;
        double ray_dx = cos(ray_angle);
        double ray_dy = sin(ray_angle);

        while (step < max_distance)
        {
            ray_x = st->player.px + ray_dx * step;
            ray_y = st->player.py + ray_dy * step;
            // Check if ray hits a wall
            if (st->scheme->map[(int)ray_y].path[(int)ray_x] == '1')
                break ;
            int pixel_x = (int)(ray_x * TILE_SIZE);
            int pixel_y = (int)(ray_y * TILE_SIZE);
            // Draw pixel at ray position
            draw_single_pixel(pixel_x, pixel_y, st, 0x00FF00);
            // cyan color for the ray
            step += 0.005;
        }
        i++;
    }
} */
