/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:26 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/09 17:52:13 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_shell_info(int argc, char **argv)
{
	if (argc > 1 && str().equals(argv[1], "--version"))
		return (printf("v1\n"), ft_exit());
	(hashmap(terminal()->env)->put)(str().copy("SHELL"),
		str().copy(argv[0]));
}

int	main(int argc, char **argv, char **env)
{
	init_env(env);
	handle_shell_info(argc, argv);
	loop();
	ft_exit();
}
