/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expanding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:05:50 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/17 15:26:48 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_env_variable(char *var_name)
{
	char	*value;

	value = hashmap(terminal()->env)->get_key(var_name);
	if (value)
		return (str().copy(value));
	return (str().copy(""));
}

int	copy_variable_name(char *dest, char *src, int i)
{
	int	k;

	k = 0;
	while (src[i] && ((str().isalnum)(src[i]) || src[i] == '_'))
		dest[k++] = src[i++];
	dest[k] = '\0';
	return (i);
}

char	*expand_arg(char *arg, int quoted)
{
	char	*result;
	char	*value;
	char	var_name[256];
	int		i;
	int		j;

	result = ft_calloc(1000);
	if (!result)
		return (NULL);
	if (quoted)
		i = 3;
	else
		i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] == '\\' && arg[i + 1] == '$')
		{
			result[j++] = '$';
			i += 2;
		}
		else if (arg[i] == '$' && arg[i + 1])
		{
			i++;
			ft_memset(var_name, 0, 256);
			if (arg[i] == '?')
			{
				value = str().itoa(terminal()->status);
				i++;
			}
			else
			{
				i = copy_variable_name(var_name, arg, i);
				value = expand_env_variable(var_name);
			}
			if (value)
			{
				ft_strlcat(result + j, value, 1000 - j);
				j += str().size(value);
				free(value);
			}
		}
		else
			result[j++] = arg[i++];
	}
	return (result);
}

char	*process_arg_expansion(char *arg)
{
	if (!arg || !*arg)
		return (str().copy(""));
	if (str().equals(arg, "$?"))
		return (str().itoa(terminal()->status));
	if (str().starts_with(arg, "sq:"))
		return (str().copy(arg + 3));
	if (str().starts_with(arg, "dq:"))
		return (expand_arg(arg, 1));
	if (str().contains(arg, "$"))
		return (expand_arg(arg, 0));
	return (str().copy(arg));
}
