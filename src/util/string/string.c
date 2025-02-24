/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2025/02/16 23:39:59 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <string_util.h>
#include <stdio.h>

char	**__copy_array_n(char **values, long long n);

static size_t	ft_size(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_copy(const char *s)
{
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	copy = ft_calloc(ft_size(s) + 1);
	while (copy && s[++i])
		copy[i] = s[i];
	copy[i] = 0;
	return (copy);
}

static int	ft_contains(const char *s, const char *hey)
{
	int	i;
	int	j;
	int	co;
	int	p;

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
				break ;
			}
		}
	}
	return (co + (co * p));
}

static int	__isnumber(const char *s)
{
	if (!s)
		return (0);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

t_string	str(void)
{
	static t_string	s = {
		ft_contains, ft_size, ft_copy, __join, __copy_n, __str_trim,
		__equals, __equals_n, __is_space, __strnstr, __size_list, __replace,
		__isalpha, __isnumeric, __isalnum, __split_spacer, __itoa, __atoi,
		__atoll, __isnumber, __copy_array_n, __fputstr, __fputnbr, __count_list,
		__join_list
	};

	return (s);
}
