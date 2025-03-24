/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:38:14 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 00:57:55 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "array_list.h"
# include <stdbool.h>
# include <utils.h>

typedef struct s_this
{
	t_array			*array;
	t_array			*array_main;
	t_hashmap		*hashmap;
	t_hashmap_p		*hashmapp;
}	t_this;

t_this	*this(void);

#endif
