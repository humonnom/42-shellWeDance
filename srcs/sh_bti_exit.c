#include "../incs/minishell.h"

void	sh_bti_exit(t_info *info)
{
	exit(exit_shell(info));
//	return (g_ret);
}
