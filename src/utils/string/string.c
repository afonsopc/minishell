/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2023/01/13 21:54:42 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char *__join(const char *str1, const char *str2);
char **__split(char const *s, char *c, int j, char **list);
char *__copy_n(const char *str, int n);
char *__str_trim(const char *str);
int __equals(const char *str1, const char *str2);
int __equals_n(const char *str1, const char *str2, int n);
int __is_space(char c);
char *__strnstr(const char *haystack, const char *needle, size_t len);
int __size_list(char **list);
char *__replace(const char *str1, const char *str2, const char *hey);
int __isalnum(char c);
char **__split_spacer(char const *s, char *spacer);
char *__itoa(int n);
int __atoi(const char *v);

char **__copy_list(const char **list);

static size_t ft_size(const char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char *ft_copy(const char *s)
{
	char *copy;
	int i;

	if (!s)
		return (NULL);
	i = -1;
	copy = ft_calloc(ft_size(s) + 1);
	while (copy && s[++i])
		copy[i] = s[i];
	copy[i] = 0;
	return (copy);
}

static int ft_contains(const char *s, const char *hey)
{
	int i;
	int j;
	int co;
	int p;

	i = -1;
	co = 0;
	p = 0;
	while (s && s[++i] && !co)
	{
		j = 0;
		while (!co && hey && hey[j] && s[i + j] && hey[j] == s[i + j])
		{
			p = i;
			j++;
			if (!hey[j] || !s[i + j])
			{
				co = !hey[j];
				break;
			}
		}
	}
	return (co + (co * p));
}

static int __isnumber(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

t_string str(void)
{
	static t_string _str = {
		ft_contains, ft_size, ft_copy, __join, __copy_n, __str_trim,
		__equals, __equals_n, __is_space, __strnstr, __size_list, __replace,
		__isalnum, __split_spacer, __itoa, __atoi, __isnumber, __copy_list};

	return (_str);
}
