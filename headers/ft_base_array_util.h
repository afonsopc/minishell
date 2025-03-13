/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_array_util.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:29:33 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:29:33 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE_ARRAY_UTIL_H
# define FT_BASE_ARRAY_UTIL_H

# include <stdio.h>
# include <stdlib.h>
# include <array_list.h>

void			__base_for_each(void (*fun)(t_element *e, void *v), void *o);
t_element		*__base_set_element(size_t index, void *value);
void			__base_remove_element_index(size_t index);
int				__base_free_element(void *value);
char			**__to_str(void);
void			__destroy_element(t_element	*e);

//				hashmap
t_element		*__put_hasmap(char *key, void	*value);
void			*__get_index_hasmap(size_t index);
void			*__get_key_hasmap(char *key);
void			__remove_index_hasmap(size_t index);
void			__remove_element_hasmap(char	*key);
char			**__to_str_hashmpa(void);
#endif
