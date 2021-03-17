#include "../incs/minishell.h"

void	free_set(t_set *set)
{
	free_darr(set->set, INF);
	free(set->cmd);
	set->cmd = NULL;
	free(set);
	set = NULL;
}
