/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:45:58 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/04 21:28:02 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static char	*append_variable_value(char *str, int *i, char *result)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	j = ++(*i);
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	tmp2 = ft_substr(str, j, *i - j);
	tmp = ft_hashmap_get_value(terminal()->env, tmp2);
	free(tmp2);
	if (tmp)
	{
		tmp2 = ft_strjoin(result, tmp);
		free(result);
		result = tmp2;
	}
	--(*i);
	return (result);
}

static void	expand_variables(char **str)
{
	int		i;
	char	*result;
	char	*tmp;

	result = NULL;
	i = -1;
	while (str[0][++i])
	{
		if (str[0][i] == '$' && (ft_isalpha(str[0][i + 1]) || str[0][i
				+ 1] == '_'))
			result = append_variable_value(str[0], &i, result);
		else
		{
			tmp = ft_strappend(result, str[0][i]);
			free(result);
			result = tmp;
		}
	}
	free(*str);
	*str = result;
}

static int	get_heredoc(char *terminator)
{
	char	*redirect_in_content;
	int		pipe_fds[2];
	pid_t	pid;

	pipe(pipe_fds);
	pid = fork();
	if (!pid)
	{
		ft_close(pipe_fds[0]);
		redirect_in_content = redirect_in_loop(terminator);
		if (!redirect_in_content)
			redirect_in_content = ft_strdup("");
		if (!ft_strstr(terminator, "\"") && !ft_strstr(terminator, "'"))
			expand_variables(&redirect_in_content);
		ft_fputstr(pipe_fds[1], redirect_in_content);
		(free(redirect_in_content), ft_close(pipe_fds[1]));
		(close_all_non_standart_fds(), ft_exit_free());
	}
	waitpid(pid, &pid, 0);
	terminal()->status = WEXITSTATUS(pid);
	if (WTERMSIG(pid) == SIGINT)
		terminal()->status = 130;
	if (WTERMSIG(pid) == SIGQUIT)
		terminal()->status = 131;
	return (ft_close(pipe_fds[1]), pipe_fds[0]);
}

static int	get_redirect_fd(t_redirect *redirect)
{
	if (ft_strlen(redirect->args[0]) == 2)
	{
		if (redirect->type == IN)
			return (get_heredoc(redirect->args[1]));
		else
			return (open(redirect->args[1], O_WRONLY | O_CREAT | O_APPEND,
					0644));
	}
	else if (redirect->type == IN)
		return (open(redirect->args[1], O_RDONLY));
	else
		return (open(redirect->args[1], O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

bool	process_redirection(t_cmd *cmd, t_redirect *redirect)
{
	int		*fd;
	char	*error_prompt;

	if (!cmd || !redirect || !redirect->args[0] || !redirect->args[1])
		return (true);
	if (redirect->type == IN)
		fd = &cmd->in;
	else
		fd = &cmd->out;
	ft_close(*fd);
	*fd = get_redirect_fd(redirect);
	if (*fd == -1 && cmd->args[0])
	{
		error_prompt = ft_strjoin("minishell: ", cmd->args[0]);
		perror(error_prompt);
		terminal()->status = 1;
		cmd->loser = true;
		cmd->loser_status = 1;
		free(error_prompt);
		return (false);
	}
	return (!terminal()->status && process_redirection(cmd, redirect->next));
}
