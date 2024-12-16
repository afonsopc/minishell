// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   base_hasmap.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
// /*   Updated: 2022/06/25 12:30:33 by edos-san         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include <ArrayList.h>
#include <ft_string.h>

typedef struct s_array_private t_array_private;
t_node *__get_node_key(char *key);
int __destroy_hasmap();

t_hashmap *hashmap(void *list)
{
    (*this()) = (void *)list;
    return (list);
}

// // // void	**__to_str_hashmpa(void)
// // // {
// // // 	t_element	*temp;
// // // 	void		**list;
// // // 	int			i;
// // // 	char		*str_temp;

// // // 	if (!fthis()->array)
// // // 		return (NULL);
// // // 	list = malloc_ob(sizeof(void *) * ((fthis()->array)->size + 1));
// // // 	if (!list)
// // // 		return (NULL);
// // // 	i = 0;
// // // 	temp = (fthis()->array)->begin;
// // // 	while (temp)
// // // 	{
// // // 		str_temp = str().join(temp->key, "=");
// // // 		list[i++] = str().join(str_temp, temp->value);
// // // 		free_ob(str_temp);
// // // 		temp = temp->next;
// // // 	}
// // // 	list[i] = NULL;
// // // 	return (list);
// // // }

// // // static int	base_destroy_hashmap(void)
// // // {
// // // 	if (!fthis()->hashmap)
// // // 		return (0);
// // // 	if (fthis()->hashmap->list)
// // // 	{
// // // 		array(fthis()->hashmap->list)->destroy();
// // // 		fthis()->hashmap->list = NULL;
// // // 	}
// // // 	free_ob(fthis()->hashmap);
// // // 	fthis()->hashmap = NULL;
// // // 	return (1);
// // // }

// // // static int	base_size_hashmap(void)
// // // {
// // // 	if (!fthis()->hashmap)
// // // 		return (0);
// // // 	return (array(fthis()->hashmap->list)->size);
// // // }

// // // t_hashmap	*hashmap(t_hashmap *a)
// // // {
// // // 	if (a)
// // // 		fthis()->array = a->list;
// // // 	fthis()->hashmap = a;
// // // 	return (a);
// // // }

// static t_node *__get_node_key(char *key)
// {
//     t_array *list;

//     if (*this() == NULL)
//         return (NULL);
//     list = ((t_hashmap *)*this())->list;
//     if (!list)
//         return (NULL);
//     array(list)->get
// }

static t_node *__put_hasmap(char *key, void *value)
{
    t_node *pair = NULL;
    t_array_private *a;
    bool is_update_key;

    a = ((t_hashmap_private *)*this())->list;
    pair = __get_node_key(key);
    is_update_key = (pair == NULL);
    if (!pair)
        pair = array((void *)a)->add(value);
    if (pair)
    {
        if (is_update_key)
            pair->key = str().copy(key);
    }
    return (pair);
}

static void *__get_key(char *key)
{
    t_node *pair;

    pair = __get_node_key(key);
    if (!pair)
        return (NULL);
    return (pair->value);
}

t_node *__get_node_key(char *key)
{
    t_hashmap_private *h;
    t_array_private *a;
    t_node *pairs;
    size_t i;

    h = *this();
    if (!h)
        return (NULL);
    a = h->list;
    if (!a || key == 0 || !a->cmp)
        return (NULL);
    pairs = a->array;
    i = 0;
    while (i < a->size)
    {
        if (pairs[i].key == key || a->cmp(pairs[i].key, key))
        {
            pairs[i].index = i;
            return (&pairs[i]);
        }
        i++;
    }
    return (NULL);
}

void *new_hashmap(void)
{
    t_hashmap_private *map;

    map = ft_calloc(sizeof(t_hashmap_private));
    if (map)
    {
        map->list = new_array(STR);
        map->put = __put_hasmap;
        map->get = __get_key;
        map->destroy = __destroy_hasmap;
        // a->get_index = __get_index_hasmap;
        // a->get_key = __get_key_hasmap;
        // a->remove_index = __remove_index_hasmap;
        // a->remove_key = __remove_element_hasmap;
        // a->destroy = base_destroy_hashmap;
        // a->for_each = __base_for_each;
        // a->size = base_size_hashmap;
        // a->to_str = __to_str_hashmpa;
        hashmap(map);
    }
    return (map);
}
