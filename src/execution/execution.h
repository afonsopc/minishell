/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:26:54 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/19 21:54:06 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <minishell.h>

void	wait_fork(void);
char	*path_join(char *str1, char *str2);
char	*get_command_path(char *cmd);
pid_t	execute(t_cmd *cmd, int fds[2]);

#endif