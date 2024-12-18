/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:26 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 23:27:06 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	loop(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell: ");
		if (!line)
			break ;
		add_history(line);
		parse(line);
		free(line);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_command	cmd;

	init_env(env);
	(void)argc;
	cmd.args = &argv[1];
	cmd.args[0] = get_command_path(str().copy(argv[1]));
	execute(&cmd);
	ft_exit();
}
