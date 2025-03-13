/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:58:34 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:26:00 by paude-so         ###   ########.fr       */
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

void	print_token(t_token	*t)
{
	if (!t)
		return ;
	printf("type: %i\n", t->type);
	// if (t->args)
	// {
	// 	printf("ARGS:\n");
	// 	for (int i=0; t->args[i] != NULL; i++)
	// 		printf("      %s\n", t->args[i]);
	// }
	// else
	// 	printf("ARGS: NULL\n");
	// if (t->left)
	// 	printf("left: %s / %s\n", t->left->type,
	// 		t->left->args ? t->left->args[0] : "NULL");
	// else
	// 	printf("left: NULL\n");
	// if (t->right)
	// 	printf("right: %s / %s\n", t->right->type,
	// 		t->right->args ? t->right->args[0] : "NULL");
	// else
	// 	printf("right: NULL\n");
	printf("balancing: %i\n", t->balancing);
	printf("===============\n");
}

void	set_errno(int err)
{
	errno = err;
}
