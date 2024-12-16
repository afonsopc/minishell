/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 13:27:07 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int __equals_n(const char *str1, const char *str2, int n)
{
	int i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
		if (i == n)
			return (1);
	}
	return (0);
}

int __equals(const char *str1, const char *str2)
{
	int i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] == str2[i]);
}

int __is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' ');
}

int __size_list(char **list)
{
	int i;

	i = 0;
	while (list && list[i])
		i++;
	return (i);
}

char *__replace(const char *str1, const char *str2, const char *hey)
{
	int i;
	char *r;
	char *temp;

	i = str().contains(str1, hey);
	r = NULL;
	if (!i)
		return (str().copy(str1));
	i--;
	r = str().copy_n(str1, i);
	str1 += (i + str().size(hey));
	temp = r;
	r = str().join(r, str2);
	free(temp);
	temp = r;
	r = str().join(r, str1);
	free(temp);
	return (r);
}
