/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_creat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:17:42 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/30 11:45:18 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_env_assignment(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !*arg)
		return (false);
	if (!(ft_isalpha(arg[i]) || arg[i] == '_'))
		return (false);
	i++;
	while (arg[i] && (ft_isalnum(arg[i]) || arg[i] == '_'))
		i++;
	return (arg[i] == '=');
}

static void	shift_args_array(char **args, int i)
{
	int	j;

	if (i > 0)
	{
		j = 0;
		while (args[i])
			args[j++] = args[i++];
		args[j] = NULL;
		if (j == 0)
		{
			args[0] = NULL;
			args[1] = NULL;
		}
	}
}

void	process_env_assignments(char **args)
{
	int		i;
	char	**env_var;

	i = 0;
	while (args[i] && is_env_assignment(args[i]))
	{
		env_var = ft_split(args[i], "=");
		if (env_var && env_var[0])
		{
			if (!env_var[1])
				env_var[1] = ft_strdup("");
			ft_hashmap_set(terminal()->env, env_var[0],
				ft_strdup(env_var[1]), free);
			ft_strvfree(env_var);
		}
		i++;
	}
	shift_args_array(args, i);
}
