/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:29:50 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/27 14:54:28 by afpachec         ###   ########.fr       */
=======
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:29:50 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/13 15:44:00 by paude-so         ###   ########.fr       */
>>>>>>> paude-so/main
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
<<<<<<< HEAD
	while (++fd <= 1024)
=======
	while (++fd <= FOPEN_MAX)
>>>>>>> paude-so/main
		ft_close(fd);
}
