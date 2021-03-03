#include "../incs/minishell.h"

void	free_set(t_set *set)
{
	int	idx;

	if (set->cmd)
		free(set->cmd);
	idx = -1;
	while (set->args[++idx])
		free(set->args[idx]);
	if (set)
		free(set);
}
