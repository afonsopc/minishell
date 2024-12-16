/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:51:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/20 13:51:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ArrayList.h"
#include <stdlib.h>

typedef struct s_array_private t_array_private;

t_node *__set_array(int index, void *value);
t_node *__get_value(void *value);
void __destroy_array();
void **__to_array();

static void *__get(int index)
{
	t_array_private *a;

	a = *this();
	if (!a || index < 0 || index >= a->size)
		return (NULL);
	return (a->array[index].value);
}

static void __for_each(void (*fun)(void *value, void *data), void *data)
{
	t_node *list;
	t_array_private *a;
	size_t i;

	a = *this();
	if (!a || !fun)
		return;
	list = a->array;
	if (!list)
		return;
	i = 0;
	while (i < a->size)
		fun(list[i++].value, data);
}

static void realloc_list(t_array_private *a)
{
	t_node *new_list;
	size_t i;

	new_list = ft_calloc((a->vsize + 1) * sizeof(t_node));
	if (!new_list)
		return;
	i = -1;
	while (++i < a->size)
		new_list[i] = a->array[i];
	free(a->array);
	a->array = new_list;
}

static t_node *__add(void *value)
{
	t_array_private *a;
	size_t index;

	a = *this();
	if (!a || !value)
		return (NULL);
	index = a->size;
	if ((a->size + 1) >= a->vsize)
	{
		a->vsize += 10;
		realloc_list(a);
	}
	a->array[index].index = index;
	a->array[index].value = value;
	a->array[index].destroy = a->destroy_element;
	a->size++;
	a->is_update = false;
	return (&a->array[index]);
}

static void __remove(void *value, bool is_free)
{
	size_t i;
	bool is_realloc;
	t_array_private *a;
	size_t size;

	a = *this();
	if (!a || !value)
		return;
	i = 0;
	is_realloc = false;
	size = a->size;
	while (i < size)
	{
		if (is_realloc)
		{
			a->array[i - 1] = a->array[i];
			a->array[i].value = NULL;
		}
		else if (a->cmp(a->array[i].value, value) && ++is_realloc)
		{
			if (is_free && a->array[i].destroy)
				a->array[i].destroy(a->array[i].value);
			a->array[i].value = NULL;
			a->size--;
		}
		i++;
	}
	a->is_update = false;
}

void *new_array(t_type_node type)
{
	t_array_private *a;

	a = extender_array(type, sizeof(t_array_private));
	if (!a)
		return (NULL);
	a->add = __add;
	a->get = __get;
	a->get_value = __get_value;
	a->set = __set_array;
	a->remove = __remove;
	a->cmp = get_cmp(type);
	a->for_each = __for_each;
	a->destroy = __destroy_array;
	a->destroy_element = free;
	a->to_array = __to_array;
	// a->size = 0;
	// a->begin = NULL;
	// a->end = NULL;
	// a->add = base_add_element;
	// a->get = base_get_element;
	// a->remove = base_remove_element;
	// a->for_each = __base_for_each;
	// a->set = __base_set_element;
	// a->remove_index = __base_remove_element_index;
	// a->to_str = __to_str;
	// a->destroy_element = __destroy_element;
	// a->is_value_destroy = 1;
	// a->remove_value = __base_remove_element_value;
	// a->remove_all = __base_remove_element_all;
	// array(a);
	return (a);
}

t_array *array(t_array *array)
{
	(*this()) = array;
	return (array);
}

void *extender_array(t_type_node type, size_t size)
{
	t_array_private *a;

	a = ft_calloc(size);
	if (!a)
		return (NULL);
	a->add = __add;
	a->get = __get;
	a->get_value = __get_value;
	a->set = __set_array;
	a->remove = __remove;
	a->cmp = get_cmp(type);
	a->for_each = __for_each;
	a->destroy = __destroy_array;
	a->to_array = __to_array;
	// a->size = 0;
	// a->begin = NULL;
	// a->end = NULL;
	// a->add = base_add_element;
	// a->get = base_get_element;
	// a->remove = base_remove_element;
	// a->for_each = __base_for_each;
	// a->set = __base_set_element;
	// a->remove_index = __base_remove_element_index;
	// a->to_str = __to_str;
	// a->destroy_element = __destroy_element;
	// a->is_value_destroy = 1;
	// a->remove_value = __base_remove_element_value;
	// a->remove_all = __base_remove_element_all;
	// array(a);
	return ((void *)a);
}
