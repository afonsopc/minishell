/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:55 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/19 21:58:50 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "../execution.h"

void	process_and(t_token *token, int fds[2]);
void	process_cmd(t_token	*token, int fds[2]);
void	process_pipe(t_token *token, int fds[2]);

#endif