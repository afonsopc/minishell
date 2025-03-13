/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:06:50 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 11:38:31 by edos-san         ###   ########.fr       */
=======
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:23:44 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:25:58 by paude-so         ###   ########.fr       */
>>>>>>> paude-so/main
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
