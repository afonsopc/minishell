/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/09 01:55:50 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <string_util.h>
#include <stdio.h>
#include <ft_util.h>

char	**__copy_array_n(char **values, long long n)
{
	char		**args;
	long long	i;

	if (n < 1)
		n = str().size_list(values);
	args = ft_calloc((sizeof(char *) * (n + 1)));
	if (!args)
		return (NULL);
	i = -1;
	while (++i < n)
		args[i] = str().copy(values[i]);
	return (args);
}

long long	__atoll(const char *v)
{
	int					i;
	unsigned long long	n;
	long long			result;

	n = 0;
	if (!v)
		return (set_errno(EINVAL), 0);
	i = (v[0] != '-') - (v[0] == '-');
	if (v[0] == '-' || v[0] == '+')
		v++;
	while (*v)
	{
		if (*v < '0' || *v > '9')
			return (set_errno(EINVAL), 0);
		else if ((n > (n * 10) + (*v - '0')))
			return (set_errno(ERANGE), 0);
		else
			n = (n * 10) + (*v - '0');
		v++;
	}
	result = n * i;
	if (result < INT64_MIN || result > INT64_MAX)
		return (set_errno(ERANGE), 0);
	return (result);
}
