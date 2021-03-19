#include "../incs/minishell.h"

char	**free_darr(char **tab, int limit)
{
	int	idx;

	idx = -1;
	while (tab[++idx] && limit--)
		free(tab[idx]);
	free(tab);
	tab = NULL;
	return (0);
}
