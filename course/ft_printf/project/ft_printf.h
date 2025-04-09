/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:05:17 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/07 17:02:09 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct s_format
{
    int justify;
    int padding;
    int has_precision;
    int precision;
    int sharp;
    int space;
    int sign;
    int width;
    char    type;
}   t_format;

int ft_printf(const char *format, ...);
t_format    init_format(void);
size_t	ft_putnbr_base(unsigned long n, char *base);
size_t  ft_putptr_hexa(void *ptr);
int	ft_putchar(char c, int fd);
size_t	ft_putnbr(int n, int fd);
int  ft_putstr(char *s, int fd);
int	ft_nbrlen(int n);
int print_c(t_format flags, int print);
int print_s(t_format flags, char *print);
int print_p(t_format flags, void *ptr);
int print_i_d(t_format flags, int num);
int print_u_x_upperx(t_format flags, unsigned long n,  char *base);
int parse_flag(t_format *flags, const char *format, int *index);
int parse_width(t_format *flags, const char *format, int *index);
int parse_precision(t_format *flags, const char *format, int *index);
void parse_type(t_format *flags, const char *format, int *index);
void print_justify_rigth(t_format flags, int *conten_length);
void print_justify_left(t_format flags, int *conten_length);
void print_padding(t_format flags, int *conten_length);
void print_precision(t_format flags, int *length, int number_length);

#endif
