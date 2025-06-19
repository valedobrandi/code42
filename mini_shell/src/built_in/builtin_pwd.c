/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:35:00 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/18 10:20:12 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	builtin_pwd(void)
{
	char	buff[1024];
	char	*cwd;

	cwd = getcwd(buff, 1024);
	if (cwd != NULL)
	{
		ft_putendl_fd(cwd, 1);
		return (0);
	}
	return (1);
}
