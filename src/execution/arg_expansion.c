/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:25:28 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/23 14:58:52 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void process_args_expansions(t_cmd *cmd);
// iterar pelos args e chamar process_arg_expansions
static void process_arg_expansions(char *arg);
// iterar pelos chars e ir juntando para dentro duma string
// se encontrar $, chamar process_dollar_expansion(char *dollar)
// se encontrar uma aspa ' ou ", chamar process_quotes_expansion(char quote)
static void process_dollar_expansion(char *dollar);
// se encontrar caracter alfanumérico continuar ate encontrar um caracter que não seja alfanumérico e substituir pela variável de ambiente
// se encontrar ? substituir pelo valor de $? (exit status)
static void process_quotes_expansion(char quote);
// se encontrar uma aspa simples, ignorar tudo até encontrar outra aspa simples
// se encontrar uma aspa dupla, substituir todas as variáveis de ambiente usando process_dollar_expansion em cada
