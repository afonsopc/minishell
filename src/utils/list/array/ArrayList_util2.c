// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_array.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/02/20 13:51:06 by edos-san          #+#    #+#             */
// /*   Updated: 2022/02/20 13:51:06 by edos-san         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
// #include <ft_base_array.h>
// #include <ft_base_array_util.h>
#include "ArrayList.h"

typedef struct s_array_private t_array_private;

t_node *__set_array(int index, void *value)
{
    t_array_private *a;

    a = *this();
    if (!a || index < 0 || index >= a->size)
        return (NULL);
    if (a->array[index].destroy)
        a->array[index].destroy(a->array[index].value);
    a->array[index].value = value;
    return (&a->array[index]);
}

void __destroy_array()
{
    t_array_private *a;
    size_t i;

    a = *this();
    if (!a)
        return;
    if (a->array)
    {
        i = 0;
        while (i < a->size)
        {
            if (a->array[i].destroy)
                a->array[i].destroy(a->array[i].value);
            i++;
        }
        free(a->array);
    }
    free(a->matrix);
    free(a);
    *this() = NULL;
}

void **__to_array()
{
    t_array_private *a;
    size_t i;

    a = *this();
    if (!a)
        return (NULL);
    if (a->is_update)
        return (a->matrix);
    free(a->matrix);
    a->matrix = ft_calloc(sizeof(void *) * (a->size + 1));
    if (!a->matrix)
        return (NULL);
    i = 0;
    while (i < a->size)
    {
        a->matrix[i] = a->array[i].value;
        i++;
    }
    a->is_update = true;
    return (a->matrix);
}

void *_int_void_(int value)
{
    void *ptr;

    ptr = ft_calloc(sizeof(int));
    if (!ptr)
        return (NULL);
    *(int *)ptr = value;
    return (ptr);
}

int _void_int_(void *value)
{
    return (*((int *)value));
}

t_node *__get_value(void *value)
{
    t_array_private *a;
    size_t i;

    a = *this();
    if (!a || value == 0 || !a->cmp)
        return (NULL);
    i = 0;
    while (i < a->size)
    {
        if (a->cmp(a->array[i].value, value))
        {
            a->array[i].index = i;
            return (&a->array[i]);
        }
        i++;
    }
    return (NULL);
}
