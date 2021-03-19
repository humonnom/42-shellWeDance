#include "../incs/minishell.h"

char	*handle_fflush(char *backup)
{
	char *ret;

	free(backup);
	backup = NULL;
	ret = ft_strjoin("", "");
	g_fsh_buf = 0; 
	return (ret);
}
