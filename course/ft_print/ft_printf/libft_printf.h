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

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
void	ft_putnbr_base(int num, char *base);
void	ft_putptr_hexa(void *ptr);

#endif
