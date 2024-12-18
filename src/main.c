/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:26 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/18 18:37:21 by edos-san         ###   ########.fr       */
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

void print_list(char **args)
{
	while (args && *args)
	{
		printf(":%s\n", *args);
		args++;
	}
	
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;

	((void)argc, (void)argv);
	// char **tes = str().split("neofetch --ascii_distro gentoo_small", " ");
	init_env(env);
	// print_list(hashmap(terminal()->env)->to_array());
	// cmd = new_cmd(tes);
	// // if (cmd)
	// // 	execute(cmd);
	// free_cmd(cmd);
	// free_list(tes);
	ft_exit();
}
