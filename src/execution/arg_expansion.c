/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:25:28 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/30 12:12:00 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static char	*expand_variable(char *var_name, int *exit_status)
{
	char	*value;

	if (!var_name || !*var_name)
		return (ft_strdup("$"));
	if (ft_strcmp(var_name, "?") == 0)
		return (ft_itoa(*exit_status));
	value = ft_hashmap_get_value(terminal()->env, var_name);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

static char	*process_dollar_expansion(char *str, int *i, int *exit_status)
{
	char	*var_name;
	char	*value;
	int		start;
	int		len;

	(*i)++;
	if (!str[*i] || str[*i] == ' ' || str[*i] == '"' || str[*i] == '\'')
		return (ft_strdup("$"));
	start = *i;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(*exit_status));
	}
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	len = *i - start;
	var_name = ft_substr(str, start, len);
	value = expand_variable(var_name, exit_status);
	free(var_name);
	return (value);
}

static char	*expand_variables_in_string(char *str, int *exit_status)
{
	int		i;
	char	*result;
	char	*tmp;
	char	*expansion;

	if (!str)
		return (NULL);
	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			expansion = process_dollar_expansion(str, &i, exit_status);
			tmp = ft_strjoin(result, expansion);
			free(result);
			free(expansion);
			result = tmp;
		}
		else
		{
			tmp = ft_charjoin(result, str[i]);
			free(result);
			result = tmp;
			i++;
		}
	}
	return (result);
}

static char	*process_quotes_expansion(char *str, int *i, int *exit_status)
{
	char	quote;
	char	*content;
	char	*result;
	int		start;

	quote = str[(*i)++];
	start = *i;
	while (str[*i] && str[*i] != quote)
		(*i)++;
	content = ft_substr(str, start, *i - start);
	if (quote == '\'')
		result = content;
	else
	{
		result = expand_variables_in_string(content, exit_status);
		free(content);
	}
	(*i)++;
	return (result);
}

static char	*process_arg_expansions(char *arg, int *exit_status)
{
	int		i;
	char	*result;
	char	*tmp;
	char	*expansion;

	if (!arg)
		return (NULL);
	result = ft_strdup("");
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			expansion = process_dollar_expansion(arg, &i, exit_status);
			tmp = ft_strjoin(result, expansion);
			free(result);
			free(expansion);
			result = tmp;
		}
		else if (arg[i] == '\'' || arg[i] == '"')
		{
			expansion = process_quotes_expansion(arg, &i, exit_status);
			tmp = ft_strjoin(result, expansion);
			free(result);
			free(expansion);
			result = tmp;
		}
		else
		{
			tmp = ft_charjoin(result, arg[i]);
			free(result);
			result = tmp;
			i++;
		}
	}
	return (result);
}

void	process_args_expansions(t_cmd *cmd)
{
	int		i;
	char	*expanded;

	if (!cmd || !cmd->args)
		return ;
	i = 0;
	while (cmd->args[i])
	{
		expanded = process_arg_expansions(cmd->args[i], &terminal()->status);
		free(cmd->args[i]);
		cmd->args[i] = expanded;
		i++;
	}
}

void	process_token_expansions(t_token *token)
{
	if (!token)
		return ;
	if (token->type != CMD)
	{
		process_token_expansions(token->left);
		process_token_expansions(token->right);
	}
	else
		process_args_expansions(token->cmd);
}

//TODO norminette