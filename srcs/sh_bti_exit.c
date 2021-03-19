#include "../incs/minishell.h"

int	sh_bti_exit(t_info *info)
{
	g_ret = 0;
	//if child process -> exit child process only
	g_ret = exit_shell(info);
	exit(0);
	return (g_ret);
}
