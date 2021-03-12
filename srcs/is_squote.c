#include "../incs/minishell.h"

int		is_squote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

