/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/18 12:23:17 by edos-san         ###   ########.fr       */
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
