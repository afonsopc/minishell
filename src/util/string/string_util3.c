/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2025/02/16 23:40:14 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <string_util.h>
#include <stdio.h>
#include <ft_util.h>

static char	*convert_base(char *s, long long n, char *base, int size_base)
{
	if (n <= -10 || n >= 10)
		s = convert_base(s, (n / size_base), base, size_base);
	*s++ = base[(n % size_base) * ((n > 0) - (n < 0))];
	*s = 0;
	return (s);
}

char	**__split_spacer(char const *str1, char *spacer)
{
	return (__split(str1, spacer, 0, 0));
}

char	*__itoa(long long n)
{
	char	buff[20];

	buff[0] = '-';
	convert_base(buff + (n < 0), n, "0123456789", 10);
	return (str().copy(buff));
}

int	__atoi(const char *v)
{
	int			i;
	long int	n;

	n = 0;
	if (!v)
		return (0);
	i = (v[0] != '-') - (v[0] == '-');
	while (*v)
	{
		if (*v != '-' && *v != '+')
			n = (n * 10) + (*v - '0');
		v++;
	}
	return (n * i);
}
