/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:18 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/30 12:00:48 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_env(char **env)
{
	char	*separator;
	char	**values;

	terminal()->env = ft_hashmap_new();
	while (env && *env)
	{
		separator = ft_strnstr(*env, "=", ft_strlen(*env));
		values = ft_calloc(3, sizeof(char *));
		values[0] = ft_strndup(*env, separator - *env);
		values[1] = ft_strdup(separator + 1);
		if (values && values[0] && *values[0])
		{
			ft_hashmap_set(terminal()->env, ft_strdup(values[0]),
				ft_strdup(values[1]), free);
		}
		ft_strvfree(values);
		env++;
	}
}
