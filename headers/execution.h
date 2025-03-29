/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:55:26 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/29 18:16:22 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <minishell.h>
# include <dirent.h>
# include <ft_utils.h>

void		unmask_signals(void);
void		mask_signals(void);
void		wait_token(t_token *token);
void		kill_token(t_token *token);
char		*path_join(char *str1, char *str2);
char		*get_command_path(char *cmd);
char		*get_cwd(void);
char		*get_curr_dir(void);
bool		process_redirections(t_token *token);
void		close_all_non_standart_fds(void);
char		*redirect_in_loop(char *terminator);
void		process_wildcards(t_cmd *cmd);
void		arg_clean(t_cmd *cmd);

void		process(t_token	*token, int in, int out);
void		process_and(t_token *token, int in, int out);
void		process_cmd(t_token	*token, int in, int out);
void		process_or(t_token *token, int in, int out);
void		process_pipe(t_token *token, int in, int out);

void		process_args_expansions(t_cmd *cmd);
void		process_token_expansions(t_token *token);
void		parse_token_redirections(t_token *token);

pid_t		execute(t_cmd *cmd);
pid_t		execute_cd(t_cmd *cmd);
pid_t		execute_pwd(t_cmd *cmd);
pid_t		execute_exit(t_cmd *cmd);
pid_t		execute_echo(t_cmd *cmd);
pid_t		execute_export(t_cmd *cmd);
pid_t		execute_env(t_cmd *cmd);
pid_t		execute_unset(t_cmd *cmd);

#endif