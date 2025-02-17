/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:40:35 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/16 23:40:46 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <string_util.h>
#include <stdio.h>
#include <ft_util.h>

int	__isalpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	__isnumeric(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	__isalnum(char c)
{
	return (__isalpha(c) || __isnumeric(c));
}
