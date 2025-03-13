/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:58:34 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 19:45:59 by paude-so         ###   ########.fr       */
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

void	set_errno(int err)
{
	errno = err;
}
