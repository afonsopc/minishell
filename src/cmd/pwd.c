/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/08 22:02:07 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_pwd(t_cmd *cmd, int in, int out)
{
	(void)cmd;
	printf("%s\n", (char *)hashmap(terminal()->env)->get_key("PWD"));
	ft_close(out);
	ft_close(in);
	return (0);
}
