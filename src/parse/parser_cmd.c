/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:40:00 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 17:03:22 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*parse_simple_command(char **tokens, size_t *pos)
{
	char	*curr;
	size_t	init_pos;

	init_pos = *pos;
	curr = tokens[*pos];
	while (curr && !ft_strequal(curr, "|") && !ft_strequal(curr, "&&")
		&& !ft_strequal(curr, "||"))
		curr = tokens[++*pos];
	return (new_token("CMD", new_cmd(ft_strvndup(&tokens[init_pos], *pos
					- init_pos))));
}
