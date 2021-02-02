#include "minishell.h"

static int	check_dquote_open(char *line)
{
	// add single quote case
	// ", ' check pair
	return (0);
}

static int	check_dquote_copy(char *line)
{
	// copy string for split_lines
	return (0);
}	


int			check_dquote(char *line, int flag)
{
	int	ret;

	ret = 0;
	if (flag == DQUOTE_OPEN)
		check_dquote_open(line);
	if (flag == DQUOTE_COPY)
		check_dquote_copy(line);
	
	return (ret);
}
