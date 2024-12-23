#include <minishell.h>

static bool	check_flag(char	*str)
{
	if (!str || *str != '-')
		return (false);
	str++;
	while (*str == 'n')
		str++;
	return ((*str == '\0'));
}

pid_t	execute_echo(t_cmd *cmd, int in, int out)
{
	bool	flag;
	size_t	i;

	flag = check_flag(cmd->args[1]);
	i = flag;
	while (cmd->args[++i])
	{	
		write(out, cmd->args[i], str().size(cmd->args[i]));
		if (cmd->args[i + 1])
			write(out, " ", 1);
	}
	if (!flag)
		write(out, "\n", 1);
	ft_close(in);
	return (0);
}