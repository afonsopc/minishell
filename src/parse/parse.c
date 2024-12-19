/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:39:36 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/19 16:17:22 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token		*new_token(char *type, t_cmd *cmd);
void		print_token(t_token	*t);
t_token		*balancing(t_token	*head, t_token *new);
t_token		*swap(t_token	*s1, t_token *s2);

t_size_ll	get_token(char **token, size_t start, t_token	**head)
{
	t_size_ll	i;
	t_token		*t;

	i = 0;
	t = NULL;
	while (1)
	{
		if (token[i] == NULL || str().equals(token[i], "|") || \
		str().equals(token[i], "||") || str().equals(token[i], "&&"))
		{
			if (i > 0)
				t = new_token("CMD", new_cmd(str().copy_array_n(token, i)));
			else
				t = new_token(token[i], NULL);
			print_token(t);
			*head = balancing(*head, t);
			return (i + (i == 0 && token[i]) + start);
		}
		i++;
	}
	return (i);
}

static t_token	*parse_tokens(char **token)
{
	size_t	i;
	t_token	*head;

	i = 0;
	head = NULL;
	while (token[i])
		i = get_token(token + i, i, &head);
	// if (head)
	// {
	// 	print_token(head);
	// 	printf("left:\n");
	// 	print_token(head->left);
	// 	printf("right:\n");
	// 	print_token(head->right);
	// }
	free_list(token);
	return (head);
}

static bool	check(char **line, char *new, size_t *len)
{
	size_t	l;

	l = *len;
	if (line[0][0] == '>' || line[0][1] == '<' ||
		(line[0][0] == '|' && line[0][1] == '|') ||
		(line[0][0] == '&' && line[0][1] == '&'))
	{
		new[len[0]++] = '\2';
		new[len[0]++] = *line[0]++;
		if (new[*len - 1] == *line[0])
			new[len[0]++] = *line[0]++;
		new[len[0]++] = '\2';
	}
	else if (line[0][0] == ')' || line[0][0] == '(' || line[0][0] == '|')
	{
		new[len[0]++] = '\2';
		new[len[0]++] = *line[0]++;
		new[len[0]++] = '\2';
	}
	return (l != *len);
}

t_token	*parse(char *line)
{
	char	flag;
	char	*new;
	size_t	len;

	flag = 0;
	len = 0;
	new = ft_calloc(str().size(line) * 10);
	if (!new)
		return NULL;
	while (*line)
	{
		if (flag == 0 && (*line == '\'' || *line == '\"'))
			flag = *line;
		else if (flag == *line)
			flag = 0;
		if (check(&line, new, &len))
			continue ;
		if (!flag && str().is_space(*line))
			*line = '\2';
		new[len++] = *line++;
	}
	return (parse_tokens(str().split(new, "\2")));
}
