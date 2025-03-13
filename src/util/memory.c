/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:15:49 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:26:01 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <minishell.h>

int	free_list(char **values)
{
	int	i;

	if (values)
	{
		i = -1;
		while (values[++i])
			free(values[i]);
		free(values);
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

void	free_redirect(t_redirect *r)
{
	if (!r)
		return ;
	free_redirect(r->next);
	free_list(r->args);
	free(r);
}
