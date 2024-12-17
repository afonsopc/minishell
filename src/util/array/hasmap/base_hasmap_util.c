/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 12:21:24 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_string.h>

t_element	*__put_hasmap(char *key, void	*value)
{
	t_element	*v;

	this()->hashmapp->update_array = false;
	v = hashmap(this()->hashmap)->get_key(key);
	if (!v)
		v = array(this()->array)->add("");
	else
	{
		free(v->key);
		free(v->value);
	}
	if (!v)
		return (0);
	v->key = key;
	v->value = value;
	return (v);
}

void	*__get_index_hasmap(size_t index)
{
	t_element	*e;

	e = array(this()->array)->get(index);
	if (e)
		return (e->value);
	return (NULL);
}

void	*__get_key_hasmap(char *key)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array)
		return (NULL);
	e = (this()->array)->begin;
	while (e)
	{
		if (string().equals(key, e->key))
			return (e->value);
		e = e->next;
		i++;
	}
	return (NULL);
}

void	__remove_element_hasmap(char	*key)
{
	if (!key || !this()->hashmap)
		return ;
	this()->hashmapp->update_array = false;
	array(this()->array)->remove(__get_key_hasmap(key));
}

void	__remove_index_hasmap(size_t index)
{
	if (!this()->hashmap)
		return ;
	this()->hashmapp->update_array = false;
	array(this()->array)->remove_index(index);
}
