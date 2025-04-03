/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cool_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:45:25 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/03 23:48:13 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static char	*get_main_info(void)
{
	char	*user;
	char	*machine;
	char	*main_info;
	char	*tmp;

	user = ft_strdup(ft_hashmap_get_value(terminal()->env, "USER"));
	machine = ft_strdup(ft_hashmap_get_value(terminal()->env, "HOSTNAME"));
	if (!user)
		user = ft_strdup("user");
	if (!machine)
		machine = ft_strdup("machine");
	tmp = ft_strjoin(user, "@");
	main_info = ft_strjoin(tmp, machine);
	if (!main_info)
		main_info = ft_strdup("user@machine");
	return (free(tmp), free(user), free(machine), main_info);
}

static char	*wrap_string_in_brackets(char *str)
{
	char	*bracketed_str;
	char	*tmp;

	tmp = ft_strjoin("[", str);
	bracketed_str = ft_strjoin(tmp, "]");
	free(tmp);
	return (bracketed_str);
}

char	*get_prompt(void)
{
	char	*main_info;
	char	*curr_dir;
	char	*prompt;
	char	*tmp;

	main_info = get_main_info();
	curr_dir = get_curr_dir();
	if (!main_info || !curr_dir)
		return (free(main_info), free(curr_dir), NULL);
	prompt = ft_strjoin(main_info, " ");
	tmp = ft_strjoin(prompt, curr_dir);
	free(prompt);
	free(main_info);
	free(curr_dir);
	prompt = tmp;
	tmp = wrap_string_in_brackets(prompt);
	free(prompt);
	prompt = ft_strjoin(tmp, "$ ");
	free(tmp);
	return (prompt);
}
