/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:29:50 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/27 14:21:25 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

char	*get_curr_dir(void)
{
	char	*cwd;
	char	**dirs;
	char	*curr_dir;

	cwd = get_cwd();
	dirs = (str().split)(cwd, "/");
	curr_dir = str().copy(dirs[str().size_list(dirs) - 1]);
	(free(cwd), free_list(dirs));
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
	kill(token->pid, SIGINT);
	terminal()->status = WEXITSTATUS(ret);
	if (!WIFEXITED(ret))
		terminal()->status = 130;
	token->pid = 0;
}
