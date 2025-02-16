/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:55:26 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/16 21:55:28 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <minishell.h>
# include <dirent.h>

void		unmask_signals(void);
void		mask_signals(void);
void		wait_token(t_token *token);
void		kill_token(t_token *token);
char		*path_join(char *str1, char *str2);
char		*get_command_path(char *cmd);
pid_t		execute(t_cmd *cmd, int in, int out);
char		*get_cwd(void);
char		*get_curr_dir(void);
bool		process_redirections(t_token *token);
void		close_all_non_standart_fds(void);
char		*redirect_in_loop(char *terminator);
void		process_wildcards(t_cmd *cmd);

void		process(t_token	*token, int in, int out);
void		process_and(t_token *token, int in, int out);
void		process_cmd(t_token	*token, int in, int out);
void		process_or(t_token *token, int in, int out);
void		process_pipe(t_token *token, int in, int out);

#endif