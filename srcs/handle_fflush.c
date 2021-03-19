#include "../incs/minishell.h"

char	*handle_fflush(char *backup)
{
	char *ret;

	free(backup);
	backup = NULL;
	ret = ft_strjoin("", "");
//	printf("[%c] -> g_fsh_buf:%d\n", buf[0], g_fsh_buf);
	g_fsh_buf = 0; 
	return (ret);
}
