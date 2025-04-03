/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_expansion_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:37:44 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/03 14:44:35 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>
#include <minishell.h>

static char	*join_expansion(char *result, char *expansion)
{
	char	*tmp;

	tmp = ft_strjoin(result, expansion);
	free(result);
	free(expansion);
	return (tmp);
}

static char	*append_char(char *result, char c)
{
	char	*tmp;

	tmp = ft_charjoin(result, c);
	free(result);
	return (tmp);
}

char	*expand_variables_in_string(char *str, int *ext_sts)
{
	int		i;
	char	*result;

	if (!str)
		return (NULL);
	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			result = join_expansion(result, process_dollar_expansion(str, &i,
						ext_sts));
		else
			result = append_char(result, str[i++]);
	}
	return (result);
}

char	*process_arg_expansions(char *arg, int *exit_status)
{
	int		i;
	char	*result;

	if (!arg)
		return (NULL);
	result = ft_strdup("");
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
			result = join_expansion(result, process_dollar_expansion(arg, &i,
						exit_status));
		else if (arg[i] == '\'' || arg[i] == '"')
			result = join_expansion(result, process_quotes_expansion(arg, &i,
						exit_status));
		else
			result = append_char(result, arg[i++]);
	}
	return (result);
}
