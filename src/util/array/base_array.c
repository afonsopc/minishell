/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:15:24 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 12:42:58 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_string.h>

void	__base_for_each(void (*fun)(t_element *e, void *v), void *o)
{
	t_element	*temp;
	t_element	*select;
	int			index;
	void		*this_list;

	if (!this()->array)
		return ;
	this_list = this()->array;
	temp = (this()->array)->begin;
	index = 0;
	while (temp)
	{
		select = temp;
		select->index = index++;
		temp = temp->next;
		fun(select, o);
		array(this_list);
	}
}

t_element	*__base_set_element(int index, void *value)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array)
		return (NULL);
	e = (this()->array)->begin;
	while (e)
	{
		if (i == index)
		{
			if (e->destroy)
				free(e->value);
			e->value = value;
			return (e);
		}
		e = e->next;
		i++;
	}
	return (0);
}

void	__base_remove_element_index(int index)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array)
		return ;
	e = (this()->array)->begin;
	while (e)
	{
		if (i == index)
		{
			(this()->array)->remove(e);
			return ;
		}
		e = e->next;
		i++;
	}
}

char	**__to_str(void)
{
	t_element	*temp;
	char		**list;
	int			i;

	if (!this()->array)
		return (NULL);
	list = ft_calloc(sizeof(char *) * ((this()->array)->size + 1));
	if (!list)
		return (NULL);
	i = 0;
	temp = (this()->array)->begin;
	while (temp)
	{
		list[i++] = str().copy(temp->value);
		temp = temp->next;
	}
	list[i] = NULL;
	return (list);
}

void	__destroy_element(t_element	*e)
{
	free(e->key);
	free(e->value);
	free(e);
}
