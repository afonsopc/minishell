/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/24 00:53:59 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

long	legal_number(char *string)
{
	long long	value;

	if (!string || !*string)
		return (ft_set_errno(EINVAL), 0);
	errno = 0;
	value = ft_atoll(string);
	if (errno)
		return (ft_set_errno(EINVAL), 0);
	return (value);
}

int	str_to_status(char *string)
{
	if (!string)
		return (0);
	return (legal_number(string) & 255);
}

void	execute_exit(t_cmd *cmd)
{
	errno = 0;
	if (cmd->args[1] && cmd->args[2])
	{
		terminal()->status = 1;
		ft_fputstr(2, "exit: too many arguments\n");
		ft_exit();
	}
	terminal()->status = str_to_status(cmd->args[1]);
	if (errno)
	{
		terminal()->status = 255;
		ft_fputstr(2, "exit: ");
		ft_fputstr(2, cmd->args[1]);
		ft_fputstr(2, ": numeric argument required\n");
	}
	ft_exit();
}
