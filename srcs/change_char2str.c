#include "../incs/minishell.h"

char	*change_char2str(char c)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

