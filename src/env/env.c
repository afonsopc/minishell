/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:01 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/09 02:47:17 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_env(char **env)
{
	char	**values;

	terminal()->env = new_hashmap();
	while (env && *env)
	{
		values = str().split(*env, "=");
		if (values && values[0] && *values[0])
		{
			(hashmap(terminal()->env)->put)(str().copy(values[0]),
				str().copy(values[1]));
		}
		free_list(values);
		env++;
	}
}
