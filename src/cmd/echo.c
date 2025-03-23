/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:36 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/23 11:38:40 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	check_flag(char *str)
{
	if (!str || *str != '-')
		return (false);
	str++;
	while (*str == 'n')
		str++;
	return ((*str == '\0'));
}

void	execute_echo(t_cmd *cmd)
{
    bool flag;
    int i;
	
    flag = check_flag(cmd->args[1]);
	i = 0;
    if (flag)
		i++;
    while (cmd->args[++i])
    {
        (str().fputstr)(1, cmd->args[i]);
        if (cmd->args[i + 1])
            (str().fputstr)(1, " ");
    }
    if (!flag)
		(str().fputstr)(1, "\n");
	terminal()->status = 0;
	ft_exit_free();
}
