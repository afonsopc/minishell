/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:16:34 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 14:11:32 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils.h>

t_hashmap	*ft_hashmap_new(void)
{
	t_hashmap	*hashmap;

	hashmap = ft_calloc(1, sizeof(t_hashmap));
	if (!hashmap)
		return (NULL);
	hashmap->table = ft_calloc(1, sizeof(t_element *));
	if (!hashmap->table)
		return (free(hashmap), NULL);
	return (hashmap);
}

t_element	*ft_element_new(char *key, void *value, void (*el_free)(void *value))
{
	t_element	*new_el;

	new_el = ft_calloc(1, sizeof(t_element));
	if (!new_el)
		return (NULL);
	new_el->key = ft_strdup(key);
	if (!new_el->key)
		return (free(new_el), NULL);
	new_el->value = value;
	new_el->value_free = el_free;
	return (new_el);
}

t_element	*ft_hashmap_get(t_hashmap *hashmap, char *key)
{
	t_element	*curr_el;

	if (!hashmap || !key)
		return (NULL);
	curr_el = hashmap->table[0];
	while (curr_el && !ft_strequal(curr_el->key, key))
		curr_el = curr_el->next;
	return (curr_el);
}

void	ft_hashmap_set(t_hashmap *hashmap, char *key, void *value, void (*el_free)(void *value))
{
	t_element	*existing_el;
	t_element	*new_el;
	int			index;

	if (!hashmap || !key)
		return ;
	existing_el = ft_hashmap_get(hashmap, key);
	if (existing_el)
	{
		if (existing_el->value_free)
			existing_el->value_free(existing_el->value);
		existing_el->value = value;
		return ;
	}
	new_el = ft_element_new(key, value, el_free);
	if (!new_el)
		return ;
	new_el->next = hashmap->table[0];
	hashmap->table[0] = new_el;
}

void	ft_hashmap_destroy(t_hashmap *hashmap)
{
	t_element	*curr_el;
	t_element	*next_el;

	if (!hashmap)
		return ;
	curr_el = hashmap->table[0];
	while (curr_el)
	{
		next_el = curr_el->next;
		if (curr_el->value_free)
			curr_el->value_free(curr_el->value);
		free(curr_el->key);
		free(curr_el);
		curr_el = next_el;
	}
	free(hashmap->table);
	free(hashmap);
}
