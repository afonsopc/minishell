/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:23:44 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:25:58 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_this	*this(void)
{
	static t_this	t;

	return (&t);
}

t_terminal	*terminal(void)
{
	static t_terminal	t;

	return (&t);
}

t_array	*array(t_array *a)
{
	this()->array = a;
	return (a);
}
