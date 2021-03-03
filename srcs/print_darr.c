#include "../incs/minishell.h"

void	print_darr(char **str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		printf("str[%d]: %s\n", idx, str[idx]);
}
