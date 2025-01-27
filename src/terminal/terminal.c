/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:23:20 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/19 12:33:02 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exit(void)
{
	printf("exit\n");
	hashmap(terminal()->env)->destroy();
	free_token(terminal()->token);
	exit(terminal()->status);
}
