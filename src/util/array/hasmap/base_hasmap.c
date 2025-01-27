/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/27 15:45:48 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_base_array_util.h>
#include <ft_util.h>
#include <ft_string.h>

t_element	*__get_element_index_hasmap(size_t index);
t_element	*__get_element_hasmap(char *key);

char	**__to_str_hashmpa(void)
{
	t_element	*temp;
	int			i;
	char		*str_temp;

	if (!this()->array)
		return (NULL);
	if (this()->hashmapp->update_array)
		return (this()->hashmapp->array);
	free_list(this()->hashmapp->array);
	this()->hashmapp->array = ft_calloc(((this()->array)->size + 1)
		* sizeof(char *));
	if (!this()->hashmapp->array)
		return (NULL);
	i = 0;
	temp = (this()->array)->begin;
	while (temp)
	{
		str_temp = str().join(temp->key, "=");
		(this()->hashmapp)->array[i++] = str().join(str_temp, temp->value);
		free(str_temp);
		temp = temp->next;
	}
	this()->hashmapp->update_array = true;
	return (this()->hashmapp->array);
}

static int	base_destroy_hashmap(void)
{
	if (!this()->hashmap)
		return (0);
	free_list(this()->hashmapp->array);
	if (this()->hashmap->list)
	{
		array(this()->hashmap->list)->destroy();
		this()->hashmap->list = NULL;
	}
	free(this()->hashmap);
	this()->hashmap = NULL;
	return (1);
}

static size_t	base_size_hashmap(void)
{
	if (!this()->hashmap)
		return (0);
	return (array(this()->hashmap->list)->size);
}

t_hashmap	*hashmap(t_hashmap *a)
{
	if (a)
		this()->array = a->list;
	this()->hashmap = a;
	this()->hashmapp = (t_hashmap_p *) a;
	return (a);
}

void	*new_hashmap(void)
{
	t_hashmap	*a;

	a = ft_calloc(sizeof(t_hashmap_p));
	if (a)
	{
		a->list = new_array();
		a->put = __put_hasmap;
		a->get_index = __get_index_hasmap;
		a->get_key = __get_key_hasmap;
		a->remove_index = __remove_index_hasmap;
		a->remove_key = __remove_element_hasmap;
		a->destroy = base_destroy_hashmap;
		a->for_each = __base_for_each;
		a->size = base_size_hashmap;
		a->to_array = __to_str_hashmpa;
		a->get_element_index = __get_element_index_hasmap;
		a->get_element_key = __get_element_hasmap;
		hashmap(a);
	}
	return (a);
}
