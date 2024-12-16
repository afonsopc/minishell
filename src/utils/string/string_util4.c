/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:32:18 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 13:33:38 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char *_str(const char c)
{
	static char buff[2];

	buff[0] = c;
	return (buff);
}

char **__copy_list(const char **list)
{
	int y;
	char **value;

	if (!list)
		return (NULL);
	value = ft_calloc(sizeof(char *) *
					  (str().size_list((char **)list) + 1));
	y = -1;
	while (list[++y])
		value[y] = str().replace(list[y], " ", "\t");
	value[y] = NULL;
	return (value);
}

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] && s1[i] != '?' && s2[i] != '?')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}