/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 11:48:53 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_string.h"
# include "array_list.h"
# include <stdbool.h>

typedef struct s_this
{
	t_array			*array;
	t_array			*array_main;
	t_hashmap		*hashmap;
	t_hashmap_p		*hashmapp;
}	t_this;

t_this	*this(void);
void	*ft_calloc(size_t __size);
void	*ft_realloc(void *ptr, size_t newsize);
int		free_list(char **str);

#endif
