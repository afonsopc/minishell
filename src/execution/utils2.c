/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:29:50 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/24 00:53:02 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

char	*get_curr_dir(void)
{
	char	*cwd;
	char	**dirs;
	char	*curr_dir;

	cwd = get_cwd();
	dirs = ft_split(cwd, "/");
	curr_dir = ft_strdup(dirs[ft_strvlen(dirs) - 1]);
	(free(cwd), ft_strvfree(dirs));
	return (curr_dir);
}

void	kill_token(t_token *token)
{
	int		ret;

	if (!token)
		return ;
	if (token->type != CMD)
		(kill_token(token->left), kill_token(token->right));
	if (!token->pid)
		return ;
	ret = kill(token->pid, SIGINT);
	terminal()->status = WEXITSTATUS(ret);
	if (!WIFEXITED(ret))
		terminal()->status = 130;
	token->pid = 0;
}

void	close_all_non_standart_fds(void)
{
	int	fd;

	fd = 2;
	while (++fd <= FOPEN_MAX)
		ft_close(fd);
}
