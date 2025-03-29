/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:18 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 13:03:38 by paude-so         ###   ########.fr       */
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
		separator = ft_strnstr(*env, "=", ft_strlen(*env));
		values = ft_calloc(3, sizeof(char *));
		values[0] = ft_strndup(*env, separator - *env);
		values[1] = ft_strdup(separator + 1);
		if (values && values[0] && *values[0])
		{
			(hashmap(terminal()->env)->put)(ft_strdup(values[0]),
				ft_strdup(values[1]));
		}
		ft_strvfree(values);
		env++;
	}
}
