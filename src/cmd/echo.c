/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:36 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:36:39 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	check_flag(char	*str)
{
	if (!str || *str != '-')
		return (false);
	str++;
	while (*str == 'n')
		str++;
	return ((*str == '\0'));
}

pid_t	execute_echo(t_cmd *cmd, int in, int out)
{
	bool	flag;
	size_t	i;

	if (str().equals(cmd->args[1], "$?"))
	{
		(str().fputnbr)(out, terminal()->status);
		(str().fputstr)(out, "\n");
		ft_close(out);
		ft_close(in);
		return (0);
	}
	flag = check_flag(cmd->args[1]);
	i = flag;
	while (cmd->args[++i])
	{
		(str().fputstr)(out, cmd->args[i]);
		if (cmd->args[i + 1])
			(str().fputstr)(out, " ");
	}
	if (!flag)
		(str().fputstr)(out, "\n");
	ft_close(out);
	ft_close(in);
	return (0);
}
