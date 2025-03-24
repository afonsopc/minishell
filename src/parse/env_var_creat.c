/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_creat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:17:42 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 00:53:09 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool is_env_assignment(char *arg)
{
    int i = 0;
    
    if (!arg || !*arg)
        return (false);
    if (!(ft_isalpha(arg[i]) || arg[i] == '_'))
        return (false);
    i++;
    while (arg[i] && (ft_isalnum(arg[i]) || arg[i] == '_'))
        i++;
    return (arg[i] == '=');
}

void process_env_assignments(char **args)
{
    int i = 0;
    char **env_var;
    
    while (args[i] && is_env_assignment(args[i]))
    {
        env_var = ft_split(args[i], "=");
        if (env_var && env_var[0])
        {
            if (!env_var[1])
                env_var[1] = ft_strdup("");
            (hashmap(terminal()->env)->put)(ft_strdup(env_var[0]), 
                                            ft_strdup(env_var[1]));
                                            ft_strvfree(env_var);
        }
        i++;
    }
    if (i > 0)
    {
        int j = 0;
        while (args[i])
            args[j++] = args[i++];
        args[j] = NULL;
		if (j == 0)
		{
			args[0] = NULL;
			args[1] = NULL;
		}
	}
}
