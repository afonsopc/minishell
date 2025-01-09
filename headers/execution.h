/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:55:26 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 02:57:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <minishell.h>

void		unmask_signals(void);
void		mask_signals(void);
void		wait_token(t_token *token);
char		*path_join(char *str1, char *str2);
char		*get_command_path(char *cmd);
pid_t		execute(t_cmd *cmd, int in, int out);
char		*get_cwd(void);
char		*get_cwd_short(void);

#endif