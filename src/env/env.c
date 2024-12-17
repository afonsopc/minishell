/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:01 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 12:21:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_env(char **env)
{
	char	**values;

	terminal()->env = new_hashmap();
	while (env && *env)
	{
		values = string().split(*env, "=");
		if (values && values[0] && *values[0])
		{	
			hashmap(terminal()->env)->put(string().copy(values[0]), \
			string().copy(values[1]));
			printf("v1: %s v2: %s\n", values[0], values[1]);
		}
		free_list(values);
		env++;
	}
	printf("pwd: %s\n", (char *) hashmap(terminal()->env)->get_key("PWD"));
	hashmap(terminal()->env)->destroy();
	
}
