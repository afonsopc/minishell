/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:29:50 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 02:56:40 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

char	*get_cwd_short(void)
{
	char	*full_cwd;
	char	*home;

	full_cwd = get_cwd();
	home = hashmap(terminal()->env)->get_key("HOME");
	return ((str().replace)(full_cwd, "~", home));
}
