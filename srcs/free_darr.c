#include "../incs/minishell.h"

char	**free_darr(char **tab, int limit)
{
	int	idx;

	idx = 0;
	while (tab[idx] && limit--)
	{
		free(tab[idx]);
		++idx;
	}
	free(tab);
	return (0);
}
