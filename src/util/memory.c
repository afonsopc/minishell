/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:15:49 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 00:54:59 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <minishell.h>

char	*_str(const char c)
{
	static char	buff[2];

	buff[0] = c;
	return (buff);
}

void	free_redirect(t_redirect *r)
{
	if (!r)
		return ;
	free_redirect(r->next);
	ft_strvfree(r->args);
	free(r);
}
