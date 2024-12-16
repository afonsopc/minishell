/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/10/24 12:40:49 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
#define FT_UTIL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_string.h"
#include "ArrayList.h"
#include <stdbool.h>

int free_list(void **values);
void *ft_calloc(size_t __size);
char *get_next_line(int fd);
void *ft_realloc(void *ptr, size_t newsize);
void **this();
#endif
