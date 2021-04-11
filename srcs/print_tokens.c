#include "../incs/minishell.h"

void	print_tokens(t_tokens *tokens)
{
	int	idx;

	printf("cmd: %s\n", tokens->cmd);
	idx = -1;
	while (tokens->args[++idx])
	{
		printf("arg[%d]: %s\n", idx, tokens->args[idx]);
	}
	printf("type: %d\n", tokens->type);
}
