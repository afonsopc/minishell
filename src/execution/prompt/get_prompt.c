/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:38:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/15 17:21:43 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static char	*get_status_bracket(void)
{
	char	*tmp;
	char	*final;
	char	*status;

	final = str().copy("[");
	tmp = final;
	status = str().itoa(terminal()->status);
	final = str().join(final, status);
	(free(status), free(tmp));
	tmp = final;
	final = str().join(final, "]");
	free(tmp);
	return (final);
}

static char	*get_left_half(void)
{
	char	*tmp;
	char	*tmp2;
	char	*final;

	final = str().copy("[mini@shell");
	tmp = final;
	final = str().join(final, " ");
	free(tmp);
	tmp2 = get_curr_dir();
	tmp = final;
	final = str().join(final, tmp2);
	(free(tmp), free(tmp2));
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
		tmp = final;
		final = str().join(final, tmp2);
		(free(tmp), free(tmp2));
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
