#include "../incs/minishell.h"

int		exit_shell(t_info *info)
{
	int ret;

	ret = 0;

#if 0
	ft_lstclear(&(info->set_str_list), &free);
	ft_lstclear(&(info->set_list), &free_set);
	ft_lstclear(&(info->env_list), &free_env);
#endif
	if (info->env_list)
	{
		ft_lstclear(&(info->env_list), &free_env);
		free(info->env_list);
		info->env_list = NULL;
	}
	return (ret);
}


