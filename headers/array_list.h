/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:29:09 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:29:09 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_LIST_H
# define ARRAY_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_element	t_element;

struct s_element
{
	char				*key;
	void				*value;
	int					index;
	void				(*destroy)(t_element	*e);
	struct s_element	*next;
};

typedef struct s_array
{
	t_element		*begin;
	t_element		*end;
	t_element		*next;
	size_t			size;
	t_element		*(*add)(void	*value);
	void			*(*get)(size_t	index);
	t_element		*(*set)(size_t index, void *value);
	void			(*remove)(t_element	*e);
	void			(*remove_index)(size_t index);
	int				(*destroy)();
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
	char			**(*to_str)(void);
}	t_array;

typedef struct s_hasmap
{
	t_array			*list;
	size_t			(*size)(void);
	t_element		*(*put)(char *key, void	*value);
	void			*(*get_index)(size_t	index);
	void			*(*get_key)(char *key);
	void			(*remove_index)(size_t	index);
	void			(*remove_key)(char *key);
	int				(*destroy)();
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
	char			**(*to_array)(void);
	t_element		*(*get_element_index)(size_t	index);
	t_element		*(*get_element_key)(char *key);
}	t_hashmap;

typedef struct s_hasmap_p
{
	t_array			*list;
	size_t			(*size)(void);
	t_element		*(*put)(char *key, void	*value);
	void			*(*get_index)(int	index);
	void			*(*get_key)(char *key);
	void			(*remove_index)(size_t	index);
	void			(*remove_key)(char *key);
	int				(*destroy)();
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
	char			**(*to_str)(void);
	t_element		*(*get_element_index)(size_t	index);
	t_element		*(*get_element_key)(char *key);
	char			**array;
	bool			update_array;
}	t_hashmap_p;

void					*new_array(void);
t_array					*array(t_array *this);
void					*new_hashmap(void);
t_hashmap				*hashmap(t_hashmap *this);

#endif