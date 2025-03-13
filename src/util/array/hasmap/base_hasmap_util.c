/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:43 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:34:45 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_string.h>

t_element	*__get_element_hasmap(char *key);

t_element	*__put_hasmap(char *key, void	*value)
{
	t_element	*v;

	this()->hashmapp->update_array = false;
	v = __get_element_hasmap(key);
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
	t_element	*e;

	if (!this()->array)
		return (NULL);
	e = (this()->array)->begin;
	while (e)
	{
		if (str().equals(key, e->key))
			return (e->value);
		e = e->next;
	}
	return (NULL);
}

void	__remove_element_hasmap(char	*key)
{
	if (!key || !this()->hashmap)
		return ;
	this()->hashmapp->update_array = false;
	array(this()->array)->remove(__get_element_hasmap(key));
}

void	__remove_index_hasmap(size_t index)
{
	if (!this()->hashmap)
		return ;
	this()->hashmapp->update_array = false;
	array(this()->array)->remove_index(index);
}
