/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:38:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 02:56:54 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static char	*get_status_bracket(void)
{
	char	*tmp;
	char	*final;

	final = str().copy("[");
	tmp = final;
	final = str().join(final, str().itoa(terminal()->status));
	free(tmp);
	tmp = final;
	final = str().join(final, "]");
	free(tmp);
	return (final);
}

static char	*get_machine_id(void)
{
	char	*final;
	char	*user;

	user = hashmap(terminal()->env)->get_key("USER");
	final = str().join(user, "@minishell");
	return (final);
}

static char	*get_left_half(void)
{
	char	*tmp;
	char	*tmp2;
	char	*final;

	final = str().copy("[");
	tmp = final;
	tmp2 = get_machine_id();
	final = str().join(final, tmp2);
	(free(tmp), free(tmp2));
	tmp = final;
	final = str().join(final, " ");
	free(tmp);
	tmp2 = get_cwd_short();
	final = str().join(final, tmp2);
	free(tmp2);
	return (final);
}

static char	*get_right_half(void)
{
	char	*tmp;
	char	*tmp2;
	char	*final;

	final = str().copy("");
	if (terminal()->status != 0)
	{
		tmp = final;
		final = str().join(final, " ");
		free(tmp);
		tmp2 = get_status_bracket();
		final = str().join(final, tmp2);
		free(tmp2);
	}
	tmp = final;
	final = str().join(final, "] ");
	free(tmp);
	return (final);
}

char	*get_prompt(void)
{
	char	*tmp;
	char	*tmp2;
	char	*final;

	final = get_left_half();
	tmp2 = get_right_half();
	tmp = final;
	final = str().join(final, tmp2);
	(free(tmp), free(tmp2));
	return (final);
}
