/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:40:35 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/13 19:37:34 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_util.h>
#include <minishell.h>
#include <stdio.h>
#include <string_util.h>

int	__isalpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	__isnumeric(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	__isalnum(char c)
{
	return (__isalpha(c) || __isnumeric(c));
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

int	__starts_with(const char *str, const char *prefix)
{
	size_t	str_len;
	size_t	prefix_len;

	if (!str || !prefix)
		return (0);
	str_len = ft_size(str);
	prefix_len = ft_size(prefix);
	if (prefix_len > str_len)
		return (0);
	return (__equals_n(str, prefix, prefix_len));
}
