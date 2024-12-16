/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:09:04 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/19 18:09:04 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "ft_util.h"
#include <stdbool.h>

typedef struct s_node t_node;
typedef struct s_array t_array;
typedef int (*t_cmp)(void *a, void *b);

typedef enum e_type_node
{
	OBJECT,
	INT,
	STR
} t_type_node;

struct s_node
{
	void *value;
	void (*destroy)(void *value);
	int index;
	char *key;
};

struct s_array
{
	size_t size;
	int is_value_destroy;
	t_node *(*add)(void *value);
	void (*remove)(void *value, bool is_free_value);
	void *(*get)(int index);
	t_node *(*get_value)(void *value);
	t_node *(*set)(int index, void *value);
	void (*remove_index)(int index);
	void (*destroy)();
	void (*destroy_element)(t_node *e);
	void (*for_each)(void (*fun)(void *value, void *data), void *o);
	void **(*to_array)(void);
	void (*remove_value)(void *value);
	void (*remove_all)(void);
	void (*test)();
	int (*cmp)(void *value, void *b);
	t_node *array;
};

struct s_array_private
{
	size_t size;
	int is_value_destroy;
	t_node *(*add)(void *value);
	void (*remove)(void *value, bool is_free_value);
	void *(*get)(int index);
	t_node *(*get_value)(void *value);
	t_node *(*set)(int index, void *value);
	void (*remove_index)(int index);
	void (*destroy)();
	void (*destroy_element)(void *e);
	void (*for_each)(void (*fun)(void *value, void *data), void *o);
	void **(*to_array)(void);
	void (*remove_value)(void *value);
	void (*remove_all)(void);
	void (*test)();
	int (*cmp)(void *a, void *b);
	t_node *array;
	size_t vsize;
	void **matrix;
	bool is_update;
};

typedef struct s_hashmap
{
	int (*size)(void);
	t_node *(*put)(char *key, void *value);
	void *(*get_index)(int index);
	void *(*get)(char *key);
	void (*remove_index)(int index);
	void (*remove)(char *key);
	int (*destroy)();
	void (*for_each)(void (*fun)(t_node *e, void *v), void *o);
	void **(*to_str)(void);
	t_array *list;
} t_hashmap;

typedef struct s_hashmap_private
{
	int (*size)(void);
	t_node *(*put)(char *key, void *value);
	void *(*get_index)(int index);
	void *(*get)(char *key);
	void (*remove_index)(int index);
	void (*remove)(char *key);
	int (*destroy)();
	void (*for_each)(void (*fun)(t_node *e, void *v), void *o);
	void **(*to_str)(void);
	struct s_array_private *list;
} t_hashmap_private;

void *new_array(t_type_node type);
t_cmp get_cmp(t_type_node type);

t_array *array(t_array *this);
void *_int_void_(int value);
int _void_int_(void *value);
void *extender_array(t_type_node type, size_t size);
void *new_hashmap(void);
t_hashmap *hashmap(void *this);

#endif
