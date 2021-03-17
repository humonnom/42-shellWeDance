#include "../incs/minishell.h"

int		exit_shell(t_info *info)
{
	int ret;

	ret = 0;
	if (info->env_list)
	{
		ft_lstclear(&(info->env_list), &free_env);
		free(info->env_list);
		info->env_list = NULL;
	}
	return (ret);
}


