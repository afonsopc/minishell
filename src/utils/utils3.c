/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:49:43 by afonsocouti       #+#    #+#             */
/*   Updated: 2025/03/29 14:10:59 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n || !s1 || !s2)
		return (0);
	n--;
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, -1));
}

void	ft_set_errno(int error)
{
	errno = error;
}

long long	ft_atoll(const char *v)
{
	int					i;
	unsigned long long	n;
	long long			result;

	n = 0;
	if (!v)
		return (ft_set_errno(EINVAL), 0);
	i = (v[0] != '-') - (v[0] == '-');
	if (v[0] == '-' || v[0] == '+')
		v++;
	while (*v)
	{
		if (*v < '0' || *v > '9')
			return (ft_set_errno(EINVAL), 0);
		else if ((n > (n * 10) + (*v - '0')))
			return (ft_set_errno(ERANGE), 0);
		else
			n = (n * 10) + (*v - '0');
		v++;
	}
	result = n * i;
	if (result < INT64_MIN || result > INT64_MAX)
		return (ft_set_errno(ERANGE), 0);
	return (result);
}

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}
