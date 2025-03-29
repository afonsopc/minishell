/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:18:01 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 15:23:15 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils.h>

void	ft_close(int fd)
{
	if (fd > 2)
		close(fd);
}

void	ft_close2(int fd1, int fd2)
{
	ft_close(fd1);
	ft_close(fd2);
}

void	ft_fprint_strv(int fd, char **strv)
{
	int	i;

	i = 0;
	while (strv && strv[i])
	{
		ft_fputstr(fd, strv[i]);
		if (strv[i + 1])
			ft_fputstr(fd, " ");
		i++;
	}
}
