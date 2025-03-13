/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:12 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/23 13:59:43 by afpachec         ###   ########.fr       */
=======
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:32:12 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 14:55:19 by paude-so         ###   ########.fr       */
>>>>>>> paude-so/main
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

<<<<<<< HEAD
=======
static void	set_token_type(t_token *t, char *type)
{
	if (str().equals("|", type))
	{
		t->type = PIPE;
		t->balancing = 1;
	}
	else if (str().equals("||", type))
	{
		t->type = OR;
		t->balancing = 1;
	}
	else if (str().equals("&&", type))
	{
		t->type = AND;
		t->balancing = 1;
	}
	else
		t->type = CMD;
}

>>>>>>> paude-so/main
t_token	*new_token(char *type, t_cmd *cmd)
{
	t_token	*t;

	if (!type)
		return (NULL);
	t = ft_calloc(sizeof(t_token));
	if (!t)
		return (NULL);
<<<<<<< HEAD
	if (str().equals("|", type))
		t->balancing = 1;
	else if (str().equals("||", type))
		t->balancing = 1;
	else if (str().equals("&&", type))
		t->balancing = 1;
	t->cmd = cmd;
	if (str().equals("|", type))
		t->type = PIPE;
	else if (str().equals("||", type))
		t->type = OR;
	else if (str().equals("&&", type))
		t->type = AND;
	else
		t->type = CMD;
=======
	t->cmd = cmd;
	set_token_type(t, type);
>>>>>>> paude-so/main
	t->pid = 0;
	return (t);
}

<<<<<<< HEAD
static t_token	*swap(t_token *s1, t_token *s2)
{
	t_token	tmp1;

	tmp1 = (*s1);
	s1->type = s2->type;
	s1->cmd = s2->cmd;
	s1->left = s2->left;
	s1->right = s2->right;
	s1->balancing = s2->balancing;
	s2->type = tmp1.type;
	s2->cmd = tmp1.cmd;
	s2->left = tmp1.left;
	s2->right = tmp1.right;
	s2->balancing = tmp1.balancing;
	return (s1);
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

=======
>>>>>>> paude-so/main
bool	free_token(t_token *token)
{
	if (!token)
		return (false);
	free_cmd(token->cmd);
	free_token(token->left);
	free_token(token->right);
	free(token);
<<<<<<< HEAD
	terminal()->token = NULL;
=======
>>>>>>> paude-so/main
	return (true);
}
