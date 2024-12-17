/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:39:36 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 16:28:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#define SEP_2 '2'
#define SEP_3 '3'

static void parse_tokens(char **token)
{
	size_t i;

	i = 0;
	while (token && token[i])
	{
		printf("%s\n", token[i++]);
	}
	free_list(token);
	
}

static bool tes(char **line, char *new, size_t *len)
{
	size_t l;

	l = *len;
	if (line[0][0] == '>' || line[0][1] == '<' ||
		(line[0][0] == '|' && line[0][1] == '|') ||
		(line[0][0] == '&' && line[0][1] == '&'))
	{
		new[len[0]++] = SEP_2;
		new[len[0]++] = *line[0]++;
		if (new[*len - 1] == *line[0])
			new[len[0]++] = *line[0]++;
		new[len[0]++] = SEP_2;
	}
	else if (line[0][0] == ')' || line[0][0] == '(' || line[0][0] == '|')
	{
		new[len[0]++] = SEP_2;
		new[len[0]++] = *line[0]++;
		new[len[0]++] = SEP_2;
	}
	return (l != *len);
}

void parse_token(char *line, char *new, void *token)
{	
	char	flag;
	size_t	len;

	flag = 0;
	len = 0;
	(void) token;
	while (*line)
	{
		if (flag == 0 && (*line == '\'' || *line == '\"'))
			flag = *line;
		else if (flag == *line)
			flag = 0;
		if (tes(&line, new, &len))
			continue ;
		if (!flag && str().is_space(*line))
			*line = SEP_2;
		new[len++] = *line++;
	}
	parse_tokens(str().split(new, "2"));
}

void parse(char *line)
{
	void	*token;

	token = new_array();
	parse_token(line, ft_calloc(str().size(line) * 10), token);
}