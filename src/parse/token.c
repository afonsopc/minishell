/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:12 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/18 15:07:30 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*new_token(char *type, char **args)
{
	t_token	*t;

	if (!type)
		return (NULL);
	t = ft_calloc(sizeof(t_token));
	if (!t)
		return (NULL);
	if (str().equals("|", type))
		t->balancing = 1;
	else if (str().equals("||", type))
		t->balancing = 1;
	else if (str().equals("&&", type))
		t->balancing = 1;
	t->args = args;
	t->type = type;
	return (t);
}

void	print_token(t_token	*t)
{
	if (!t)
		return ;
	printf("type: %s\n", t->type);
	if (t->args)
	{	
		printf("ARGS:\n");
		for (int i=0; t->args[i] != NULL; i++)
			printf("      %s\n", t->args[i]);
	}
	else
		printf("ARGS: NULL\n");
	if (t->left)
		printf("left: %s / %s\n", t->left->type, t->left->args ? t->left->args[0] : "NULL");
	else
		printf("left: NULL\n");
	if (t->right)
		printf("right: %s / %s\n", t->right->type, t->right->args ? t->right->args[0] : "NULL");
	else
		printf("right: NULL\n");
	printf("balancing: %i\n", t->balancing);
	printf("===============\n");
}

t_token *swap(t_token	*s1, t_token *s2)
{
	t_token tmp1;

	tmp1 = (*s1);
	s1->type = s2->type;
	s1->args = s2->args;
	s1->left = s2->left;
	s1->right = s2->right;
	s1->balancing = s2->balancing;
	s2->type = tmp1.type;
	s2->args = tmp1.args;
	s2->left = tmp1.left;
	s2->right = tmp1.right;
	s2->balancing = tmp1.balancing;
	return (s1);
}

static bool insert(t_token	*head, t_token *new)
{
	bool r;

	r = false;
	if (!head || str().equals(head->type, "CMD"))
		return (false);
	if (head->left == NULL)
	{
		head->left = new;
		return (true);
	}
	else
		r = insert(head->left, new);
	if (r)
		return (true);
	if (!r && head->right == NULL)
	{
		head->right = new;
		return (true);
	}
	else
		r = insert(head->right, new);
	return (r);
}

t_token	*balancing(t_token	*head, t_token *new)
{
	if (!head)
		return (new);
	if (new->balancing > head->balancing)
		swap(head, new);
	if (head->left == NULL)
		head->left = new;
	else if (head->right == NULL)
		head->right = new;
	else 
		balancing(head->right, new);
	return (head);
}