/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:26 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/19 16:30:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	loop(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell: ");
		if (!line)
			break ;
		add_history(line);
		terminal()->token = parse(line);
		free(line);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	init_env(env);
	loop();
	ft_exit();
}
