/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap_util2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:50 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 00:58:16 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_element	*__get_element_index_hasmap(size_t index)
{
	t_element	*e;
	size_t		i;

	if (!this()->array)
		return (NULL);
	e = (this()->array)->begin;
	i = 0;
	while (e)
	{
		if (i++ == index)
			return (e);
		e = e->next;
	}
	return (NULL);
}

t_element	*__get_element_hasmap(char *key)
{
	t_element	*e;

	if (!this()->array)
		return (NULL);
	e = (this()->array)->begin;
	while (e)
	{
		if (ft_strcmp(key, e->key))
			return (e);
		e = e->next;
	}
	return (NULL);
}
