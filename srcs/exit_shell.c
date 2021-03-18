#include "../incs/minishell.h"

int		exit_shell(t_info *info)
{
	if (info->env_list)
	{
		ft_lstclear(&(info->env_list), &free_env);
		free(info->env_list);
		info->env_list = NULL;
	}
	exit(g_ret);
	return (g_ret);
}


