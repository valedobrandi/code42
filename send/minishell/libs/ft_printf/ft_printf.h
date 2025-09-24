/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:05:17 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:36:58 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int		justify;
	int		padding;
	int		has_precision;
	int		precision;
	int		sharp;
	int		space;
	int		sign;
	int		width;
	char	type;
}			t_format;

int			ft_printf(const char *format, ...);
t_format	init_format(void);
int			ft_putnbr_base(unsigned long n, char *base);
int			ft_putptr_hexa(void *ptr);
int			ft_putchar(char c, int fd);
int			ft_putnbr(int n, int fd);
int			ft_putstr(char *s, int fd);
int			print_c(t_format flag, int print);
int			print_s(t_format flag, char *print);
int			print_p(t_format flag, void *ptr);
int			print_i_d(t_format flag, int num);
int			print_u_x_upperx(t_format flag, unsigned long n, char *base);
int			parse_flag(t_format *flag, const char *format, int *index);
int			parse_width(t_format *flag, const char *format, int *index);
int			parse_precision(t_format *flag, const char *format, int *index);
void		parse_type(t_format *flag, const char *format, int *index);
void		parse_printf(t_format *flag, const char *format, int *index);
void		print_justify_rigth(t_format flag, int *conten_length);
void		print_justify_left(t_format flag, int *conten_length);
void		print_padding(t_format flag, int *conten_length);
void		print_precision(t_format flag, int *length, int number_length);
void		print_space(t_format flag, int num, int *length);
void		print_sign(t_format flag, int num, int *length);
void		manage_print(int *count, t_format flag, va_list args);

#endif
