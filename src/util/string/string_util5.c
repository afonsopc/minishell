/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/09 02:07:54 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <string_util.h>
#include <stdio.h>
#include <ft_util.h>

ssize_t	__fputstr(int fd, char *string)
{
	return (write(fd, string, str().size(string)));
}

ssize_t	__fputnbr(int fd, long long number)
{
	char	*string;

	string = str().itoa(number);
	if (!string)
		return (-1);
	return (__fputstr(fd, string));
}
