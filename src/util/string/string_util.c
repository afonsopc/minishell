/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:44:16 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:26:04 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <string_util.h>
#include <stdio.h>

char	*__join(const char *str1, const char *str2)
{
	char	*s;
	int		i;

	if (!str2)
		return (str().copy(str1));
	s = ft_calloc(str().size((char *) str1) \
	+ str().size((char *) str2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str1 && *str1)
		s[i++] = *str1++;
	while (str2 && *str2)
		s[i++] = *str2++;
	s[i] = 0;
	return (s);
}

/***
 * separador c or \n
 * ***/
char	**__split(char const *s, char *c, int j, char **list)
{
	char	*t;
	int		i;

	i = 0;
	t = 0;
	while (s && (str().contains(c, _str(*s)) || *s == '\n') && *s)
		s++;
	while (s && (!str().contains(c, _str(s[i])) && s[i] != '\n') && s[i])
		i++;
	if (i > 0)
		t = ft_calloc((i + 1) * sizeof(char));
	if (i > 0)
		t[i] = 0;
	i = 0;
	while (s && t && s && (!str().contains(c, _str(*s)) && *s != '\n') && *s)
		t[i++] = *s++;
	if (++j >= 0 && i)
		list = __split(s, c, j, list);
	else if (!list)
		list = ft_calloc((j + 2) * sizeof(char *));
	if (list)
		list[--j] = t;
	return (list);
}

/*
copys n characters of string 
*/
char	*__copy_n(const char *s, int n)
{
	char	*copy;
	int		i;

	if (!s && n <= 0)
		return (NULL);
	i = -1;
	copy = ft_calloc(n + 1);
	if (!copy)
		return (NULL);
	while (copy && s[++i] && i < n)
		copy[i] = s[i];
	copy[i] = 0;
	return (copy);
}

/*
return a copy of the string but without whitespace AROUND the string
*/
char	*__str_trim(const char *s)
{
	int		size;

	if (!s)
		return (NULL);
	while (s && *s && str().is_space(*s))
		s++;
	size = str().size(s) - 1;
	while (size > 0 && s[size] && str().is_space(s[size]))
		size--;
	return (str().copy_n(s, size + 1));
}

char	*__strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	i2;

	if (*needle == 0 || needle == NULL)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		i2 = i;
		while (needle[j] == haystack[i2] && i2 < len)
		{
			if (needle[j + 1] == 0)
				return ((char *)&haystack[i]);
			j++;
			i2++;
		}
		i++;
	}
	return (NULL);
}
