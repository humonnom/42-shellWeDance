#include "../incs/minishell.h"

int has_bracket(char *c)
{
	if (exact_strncmp(c, "<") == 0)
		return (TYPE_REIN);
	if (exact_strncmp(c, ">") == 0)
		return (TYPE_REOUT);
	if (exact_strncmp(c, ">>") == 0)
		return (TYPE_REOUT_D);
	return (0);
}
