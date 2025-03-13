/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:55:26 by edos-san          #+#    #+#             */
/*   Updated: 2025/01/27 15:57:40 by afpachec         ###   ########.fr       */
=======
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:35:15 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:35:16 by paude-so         ###   ########.fr       */
>>>>>>> paude-so/main
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **env)
{
	((void)argc, (void)argv);
	init_env(env);
	loop();
	ft_exit();
}
