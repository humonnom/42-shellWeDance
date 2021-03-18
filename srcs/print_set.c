#include "../incs/minishell.h"

void	print_set(t_set *set)
{
	int	idx;

	printf("cmd: %s\n", set->cmd);
	idx = -1;
	while (set->args[++idx])
	{
		printf("arg[%d]: %s\n", idx, set->args[idx]);
	}
	printf("type: %d\n", set->type);
}
