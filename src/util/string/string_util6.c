/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:40:35 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/17 12:59:28 by paude-so         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	while (dst[i++])
		dst_len++;
	while (src[i++])
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
