/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:58:34 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/23 17:57:02 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	// 	printf("left: %s / %s\n", t->left->type, t->left->args ? t->left->args[0] : "NULL");
	// else
	// 	printf("left: NULL\n");
	// if (t->right)
	// 	printf("right: %s / %s\n", t->right->type, t->right->args ? t->right->args[0] : "NULL");
	// else
	// 	printf("right: NULL\n");
	printf("balancing: %i\n", t->balancing);
	printf("===============\n");
}
