/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:01 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/27 15:51:32 by afpachec         ###   ########.fr       */
=======
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:18 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:36:19 by paude-so         ###   ########.fr       */
>>>>>>> paude-so/main
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_env(char **env)
{
	char	*separator;
	char	**values;

	terminal()->env = new_hashmap();
	while (env && *env)
	{
		separator = str().strnstr(*env, "=", str().size(*env));
		values = ft_calloc(3 * sizeof(char *));
		values[0] = str().copy_n(*env, separator - *env);
		values[1] = str().copy(separator + 1);
		if (values && values[0] && *values[0])
		{
			(hashmap(terminal()->env)->put)(str().copy(values[0]),
				str().copy(values[1]));
		}
		free_list(values);
		env++;
	}
}
