#include "../incs/minishell.h"

int is_bracket(char c)
{
	if (c == '>')
		return (1);
	if (c == '<')
		return (1);
	return (0);
}
