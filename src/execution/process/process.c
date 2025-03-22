/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:29 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/22 15:16:25 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	process(t_token	*token, int in, int out)
{
	if (!token)
		return ;
	if (token->type == CMD)
		process_cmd(token, in, out);
	else if (token->type == AND)
		process_and(token, in, out);
	else if (token->type == PIPE)
		process_pipe(token, in, out);
	else if (token->type == OR)
		process_or(token, in, out);
}

void print_token2(t_token *t, int nivel)
{
    if (!t)
    {
        fprintf(stderr, "Erro: Token nulo passado para print_token2().\n");
        return;
    }
    
    for (int i = 0; i < nivel; i++)
        printf("  "); // Indentação baseada no nível
    printf("====================\n");
    
    // Print token type as text instead of just number
    for (int i = 0; i < nivel; i++)
        printf("  ");
    
    char *type_str;
    switch (t->type) {
        case CMD: type_str = "CMD"; break;
        case PIPE: type_str = "PIPE"; break;
        case OR: type_str = "OR"; break;
        case AND: type_str = "AND"; break;
        default: type_str = "UNKNOWN"; break;
    }
    printf("Tipo: %s (%i)\n", type_str, t->type);
    
    // Print command information when type is CMD
    if (t->type == CMD && t->cmd)
    {
        // Print arguments
        if (t->cmd->args)
        {
            for (int i = 0; i < nivel; i++)
                printf("  ");
            printf("Argumentos:\n");
            
            for (int i = 0; t->cmd->args[i] != NULL; i++)
            {
                for (int j = 0; j < nivel; j++)
                    printf("  ");
                printf("    - %s\n", t->cmd->args[i]);
            }
        }
        else
        {
            for (int i = 0; i < nivel; i++)
                printf("  ");
            printf("Argumentos: (nenhum)\n");
        }
        
        // Print redirections
        if (t->cmd->redirect)
        {
            for (int i = 0; i < nivel; i++)
                printf("  ");
            printf("Redirecionamentos:\n");
            
            t_redirect *redir = t->cmd->redirect;
            while (redir)
            {
                for (int i = 0; i < nivel; i++)
                    printf("  ");
                
                printf("    - Tipo: %s\n", redir->type == IN ? "IN" : "OUT");
                
                // Print redirection arguments
                if (redir->args)
                {
                    for (int j = 0; redir->args[j] != NULL; j++)
                    {
                        for (int i = 0; i < nivel; i++)
                            printf("  ");
                        printf("      Arg: %s\n", redir->args[j]);
                    }
                }
                
                redir = redir->next;
            }
        }
    }
    
    for (int i = 0; i < nivel; i++)
        printf("  ");
    printf("====================\n");
    
    if (t->left)
    {
        printf("\n");
        for (int i = 0; i < nivel; i++)
            printf("  ");
        printf("<< Esquerda:\n");
        print_token2(t->left, nivel + 1);
    }
    
    if (t->right)
    {
        printf("\n");
        for (int i = 0; i < nivel; i++)
            printf("  ");
        printf(">> Direita:\n");
        print_token2(t->right, nivel + 1);
    }
}
void	process_token(t_token	*token)
{
	if (!token || !process_redirections(token))
		return ;
	print_token2(token, 0);
	process(token, 0, 1);
	wait_token(token);
}
