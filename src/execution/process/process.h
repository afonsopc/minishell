/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:55 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/23 15:27:44 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "../execution.h"

void	process(t_token	*token, int in, int out);
void	process_and(t_token *token, int in, int out);
void	process_cmd(t_token	*token, int in, int out);
void	process_or(t_token *token, int in, int out);
void	process_pipe(t_token *token, int in, int out);

#endif