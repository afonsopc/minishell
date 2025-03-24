/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 00:46:10 by afonsocouti       #+#    #+#             */
/*   Updated: 2025/03/24 00:57:19 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

char    **ft_strvndup(char **v, size_t n)
{
    char    **new;
    size_t  i;

    new = ft_calloc(n + 1, sizeof(char *));
    if (!new)
        return (NULL);
    i = -1;
    while (v[++i] && i < n)
        new[i] = ft_strdup(v[i]);
    return (new);
}

char    **ft_strvdup(char **v)
{
    return (ft_strvndup(v, ft_strvlen(v)));
}

void ft_strvfree(char **v)
{
    int i;

    if (!v)
        return ;
    i = -1;
    while (v[++i])
        free(v[i]);
    free(v);
    return ;
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		ptr[n - 1] = 0;
		n--;
	}
}
