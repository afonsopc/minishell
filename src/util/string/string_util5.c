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

ssize_t	__count_list(char **lst)
{
	ssize_t	count;

	count = -1;
	if (!lst)
		return (count);
	while (lst[++count])
		;;
	return (count);
}

// TODO: NOT WORKING :(
char	**__join_list(char **lst1, char **lst2)
{
	char	**new_lst;
	ssize_t	lst1_size;
	ssize_t	lst2_size;
	ssize_t	i;

	lst1_size = __count_list(lst1);
	lst2_size = __count_list(lst2);
	((lst1_size == -1 && ++lst1_size) || (lst2_size == -1 && ++lst2_size));
	printf("%li, %li\n", lst1_size, lst1_size);
	new_lst = ft_calloc(sizeof(char *) * (lst1_size + lst2_size + 1));
	i = -1;
	while (++i < lst1_size)
		new_lst[i] = str().copy(lst1[i]);
	i = lst1_size - 1;
	while (++i - lst1_size < lst2_size)
		new_lst[i] = str().copy(lst2[i]);
	return (new_lst);
}
