/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:58:34 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 00:53:55 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_close(int fd)
{
	if (fd > 2)
		return (close(fd));
	return (-1);
}

void	print_list(char **args)
{
	while (args && *args)
	{
		printf(":%s\n", *args);
		args++;
	}
}
