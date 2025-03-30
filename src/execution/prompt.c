/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:56:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/30 12:16:30 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

// void	print_token2(t_token *t, int nivel)
// {
// 	char		*type_str;
// 	t_redirect	*redir;

// 	if (!t)
// 	{
// 		fprintf(stderr, "Erro: Token nulo passado para print_token2().\n");
// 		return ;
// 	}
// 	for (int i = 0; i < nivel; i++)
// 		printf("  "); // Indentação baseada no nível
// 	printf("====================\n");
// 	// Print token type as text instead of just number
// 	for (int i = 0; i < nivel; i++)
// 		printf("  ");
// 	switch (t->type)
// 	{
// 	case CMD:
// 		type_str = "CMD";
// 		break ;
// 	case PIPE:
// 		type_str = "PIPE";
// 		break ;
// 	case OR:
// 		type_str = "OR";
// 		break ;
// 	case AND:
// 		type_str = "AND";
// 		break ;
// 	default:
// 		type_str = "UNKNOWN";
// 		break ;
// 	}
// 	printf("Tipo: %s (%i)\n", type_str, t->type);
// 	// Print command information when type is CMD
// 	if (t->type == CMD && t->cmd)
// 	{
// 		// Print arguments
// 		if (t->cmd->args)
// 		{
// 			for (int i = 0; i < nivel; i++)
// 				printf("  ");
// 			printf("Argumentos:\n");
// 			for (int i = 0; t->cmd->args[i] != NULL; i++)
// 			{
// 				for (int j = 0; j < nivel; j++)
// 					printf("  ");
// 				printf("    - %s\n", t->cmd->args[i]);
// 			}
// 		}
// 		else
// 		{
// 			for (int i = 0; i < nivel; i++)
// 				printf("  ");
// 			printf("Argumentos: (nenhum)\n");
// 		}
// 		if (t->cmd->loser)
// 		{
// 			for (int i = 0; i < nivel; i++)
// 				printf("  ");
// 			printf("Big Loser: %d\n", t->cmd->loser_status);
// 		}
// 		for (int i = 0; i < nivel; i++)
// 			printf("  ");
// 		printf("IN: %d\n", t->cmd->in);
// 		for (int i = 0; i < nivel; i++)
// 			printf("  ");
// 		printf("OUT: %d\n", t->cmd->out);
// 		// Print redirections
// 		if (t->cmd->redirect)
// 		{
// 			for (int i = 0; i < nivel; i++)
// 				printf("  ");
// 			printf("Redirecionamentos:\n");
// 			redir = t->cmd->redirect;
// 			while (redir)
// 			{
// 				for (int i = 0; i < nivel; i++)
// 					printf("  ");
// 				printf("    - Tipo: %s\n", redir->type == IN ? "IN" : "OUT");
// 				// Print redirection arguments
// 				if (redir->args)
// 				{
// 					for (int j = 0; redir->args[j] != NULL; j++)
// 					{
// 						for (int i = 0; i < nivel; i++)
// 							printf("  ");
// 						printf("      Arg: %s\n", redir->args[j]);
// 					}
// 				}
// 				redir = redir->next;
// 			}
// 		}
// 	}
// 	for (int i = 0; i < nivel; i++)
// 		printf("  ");
// 	printf("====================\n");
// 	if (t->left)
// 	{
// 		printf("\n");
// 		for (int i = 0; i < nivel; i++)
// 			printf("  ");
// 		printf("<< Esquerda:\n");
// 		print_token2(t->left, nivel + 1);
// 	}
// 	if (t->right)
// 	{
// 		printf("\n");
// 		for (int i = 0; i < nivel; i++)
// 			printf("  ");
// 		printf(">> Direita:\n");
// 		print_token2(t->right, nivel + 1);
// 	}
// }

void	loop(void)
{
	char	*line;

	while (1)
	{
		mask_signals();
		line = readline("minishell$ ");
		if (!line)
			ft_exit();
		if (ft_strlen(line))
			add_history(line);
		terminal()->token = parse(line);
		process_token(terminal()->token);
		free(line);
	}
}

char	*redirect_in_loop(char *terminator)
{
	char	*line;
	char	*lines;
	char	*tmp;

	lines = NULL;
	unmask_signals();
	while (1)
	{
		line = readline("> ");
		if (!line)
			ft_exit();
		if (ft_strcmp(line, terminator) == 0)
		{
			free(line);
			break ;
		}
		tmp = lines;
		lines = ft_strjoin(lines, line);
		free(tmp);
		tmp = lines;
		lines = ft_strjoin(lines, "\n");
		free(tmp);
		free(line);
	}
	return (lines);
}

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		kill_token(terminal()->token);
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
	}
	rl_redisplay();
}

void	mask_signals(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}

void	unmask_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
