#include "../incs/minishell.h"

void	free_tokens(void *_tokens)
{
	t_tokens	*tokens;

	tokens = (t_tokens *)_tokens;
	free_darr(tokens->tokens, INF);
	free(tokens->cmd);
	tokens->cmd = NULL;
	free(tokens);
	tokens = NULL;
}
