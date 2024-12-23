/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap_util2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/23 18:06:26 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_string.h>

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
		if (str().equals(key, e->key))
			return (e);
		e = e->next;
	}
	return (NULL);
}
