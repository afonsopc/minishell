/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:39:36 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 14:39:44 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void parse_token(void *token)
{
	char 	**tokens;
	size_t	i;

	printf("token: %zu\n", array(token)->size);
	tokens = array(token)->to_str();
	array(token)->destroy();
	i = 0;
	while (tokens && tokens[i])
	{
		printf("%s\n", tokens[i++]);
	}
	free_list(tokens);
	
}

void parse(char *line)
{	
	char	flag;
	long	len;
	void	*token;
	char	*value;

	flag = 0;
	token = new_array();
	len = -1;
	while (line[++len])
	{
		if (flag == 0 && (line[len] == '\'' || line[len] == '\"'))
			flag = line[len];
		else if (flag == line[len])
			flag = 0;
		if (len && ((!flag && str().is_space(line[len])) || !line[len + 1]))
		{
			value = str().copy_n(line, len + (line[len + 1] == '\0'));
			array(token)->add(str().trim(value));
			free(value);
			line += len + (line[len + 1] == '\0');
			len = -1;
		}
	}
	parse_token(token);
}


