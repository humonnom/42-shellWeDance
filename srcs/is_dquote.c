#include "../incs/minishell.h"

int		is_dquote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}
