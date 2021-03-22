#include "../incs/minishell.h"

int is_bracket(char c1, char c2)
{
	if (c1 == '>' && c2 == '>')
		return (TYPE_REOUT_D);
	if (c1 == '>')
		return (TYPE_REOUT);
	if (c1 == '<')
		return (TYPE_REIN);
	return (0);
}
