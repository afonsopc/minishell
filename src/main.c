/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:26 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 11:26:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	loop(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		add_history(line);
		if (line)
			printf("%zu\n", string().size(line));
	}
}

int	main(int arc, char **argv, char **env)
{
	(void) arc;
	(void) argv;
	init_env(env);
	return (0);
}
