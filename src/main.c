/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:26 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/23 15:12:26 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*prompt(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*line;

	if (terminal()->status == 0)
		return (readline("minishell: "));
	s1 = str().itoa(terminal()->status);
	if (!s1)
		return (NULL);
	s2 = str().join("minishell [", s1);
	if (!s2)
		return (free(s1), NULL);
	s3 = str().join(s2, "]: ");
	if (!s3)
		return (free(s1), free(s2), NULL);
	line = readline(s3);
	(free(s1), free(s2), free(s3));
	return (line);
}

static void	loop(void)
{
	char	*line;

	while (1)
	{
		line = prompt();
		if (!line)
			break	;
		if (str().size(line))
			add_history(line);
		process_token(parse(line));
		free(line);
	}
}

int	main(int _, char **__, char **env)
{
	init_env(env);
	loop();
	ft_exit();
}
