#include "../incs/minishell.h"

void	free_set(t_set *set)
{
	int	idx;

	if (set->cmd)
		free(set->cmd);
	idx = -1;
	free_darr(set->args, INF);
	if (set)
		free(set);
}
