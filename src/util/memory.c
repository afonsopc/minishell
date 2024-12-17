/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 11:38:10 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <minishell.h>

int	free_list(char **str)
{
	int	i;

	if (str)
	{
		i = -1;
		while (str[++i])
			free(str[i]);
		free(str);
		return (i);
	}
	return (0);
}

char	*_str(const char c)
{
	static char	buff[2];

	buff[0] = c;
	return (buff);
}

void	*ft_calloc(size_t __size)
{
	void			*v;
	unsigned char	*temp;

	if (__size < 1)
		return (NULL);
	v = malloc(__size);
	if (!v)
		return (NULL);
	temp = (unsigned char *)v;
	while (__size-- > 0)
		*(temp++) = (unsigned char)0;
	return (v);
}

void	*ft_realloc(void *ptr, size_t newsize)
{
	char			*newptr;
	unsigned char	*tmp;
	int				i;
	size_t			cursize;

	if (ptr == 0)
		return (ft_calloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = ft_calloc(newsize);
	tmp = (unsigned char *)ptr;
	i = -1;
	while (tmp[i++])
		newptr[i] = tmp[i];
	free(ptr);
	return (newptr);
}
