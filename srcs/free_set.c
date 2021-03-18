#include "../incs/minishell.h"

void	free_set(void *_set)
{
	t_set	*set;

	set = (t_set *)_set;
	free_darr(set->set, INF);
	free(set->cmd);
	set->cmd = NULL;
	free(set);
	set = NULL;
}
