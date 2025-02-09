#include <unistd.h>
#include <stdio.h>
int grid[4][4];
int colup[4];
int coldown[4];
int rowleft[4];
int rowright[4];

int		*get_row(int index, int rev, int *t)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (rev)
			t[i] = grid[index][3 - i];
		else
			t[i] = grid[index][i];
		i += 1;
	}

	return (t);
}

int		*get_col(int index, int rev, int *t)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (rev)
			t[i] = grid[3 - i][index];
		else
			t[i] = grid[i][index];
		i += 1;
	}
	return (t);
}


void print()
{
	int col;
	int row;
	char t;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			t = grid[row][col] + '0';
			write(1, &t, 1);
			write(1, " ", 1);
			col += 1;
		}
		write(1, "\n", 1);
		row += 1;
	}
	write(1, "\n", 1);
}

int check_duplicate(int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		i += 1;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == num )
			return (0);
		i += 1;
	}
	return (1);
}

int is_visible(int *arr)
{
	int size;
	int count_visible;
	int i;

	size = 0;
	count_visible = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] > size)
		{
			size = arr[i];
			count_visible += 1;
		}
		i += 1;
	}
	return (count_visible);
}

int check_clues()
{
	int col;
	int	arr[4];

	col = 0;
	while (col < 4)
	{
		get_col(col, 0, arr);
		if (is_visible(arr) != colup[col])
			return (0);
		get_row(col, 0, arr);
		if (is_visible(arr) != rowleft[col])
			return (0);
		col += 1;
	}

	col = 0;
	while (col < 4)
	{
		get_col(col, 1, arr);
		if (is_visible(arr) != coldown[col])
			return (0);
		get_row(col, 1, arr);
		if (is_visible(arr) != rowright[col])
			return (0);
		col += 1;
	}
	return (1);
}

int fill_grid(char row, char col)
{
	int i;	
	int next_row;
    int next_col;

	if (col == 3) {
    next_row = row + 1;
    next_col = 0;
	} else {
		next_row = row;
		next_col = col + 1;
	}
	if (row == 4) 
		if (check_clues()) 
				return 1;  
	i = 1;
	while (i <= 4)
	{
		print();
		if (check_duplicate(row, col, i))
		{
			grid[row][col] = i;
			if (fill_grid(next_row, next_col))
				return (1);
			grid[row][col] = 0;
		}
		i += 1;
	}

	return (0);
}

void fill_clues(int *input, int *arr)
{
	int i;
	
	i = 0;
	while (i < 4)
	{	
		arr[i] = input[i];
		i += 1;
	}
}

void	get_params(char *argv, int input[16])
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (argv[i])
	{
		if (argv[i] >= '1' && argv[i] <= '4')
		{
			input[e] = argv[i] - '0';
			e += 1;
		}
		i += 1;
	}
}


int main(int argn, char **argv)
{
	int input[16];
	int *ptr;

	get_params(argv[1], input);
	ptr = &input[0];
	fill_clues(ptr, colup);
	ptr = &input[4];
	fill_clues(ptr, coldown);
	ptr = &input[8];
	fill_clues(ptr, rowleft);
	ptr = &input[12];
	fill_clues(ptr, rowright);
	if (fill_grid(0, 0))
	{
		write(1, "Success\n", 8);
		print();
	}
	else
		write(1, "\nError\n", 7);
}
