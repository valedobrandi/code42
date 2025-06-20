/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_directions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:03:11 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 15:28:59 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsedef.h"
#include "libft.h"

int	validate_directions(int current_token, t_token_list *token_list, int i)
{
	if (!is_operator_valid(current_token, token_list->tokens[i].value))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(token_list->tokens[i].value, 2);
		ft_putendl_fd("'", 2);
		return (1);
	}
	if (!is_valid_redirection_target(token_list, i))
		return (print_prompt(error_token_newline, 2), 1);
	return (0);
}
