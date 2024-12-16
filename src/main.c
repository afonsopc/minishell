#include <minishell.h>

int main(int, char **)
{
	char *line;
	
	while (1)
	{
		line = readline("minishell> ");
		if (line)
			printf("%zu\n", string().size(line));
	}
	return 0;
}
