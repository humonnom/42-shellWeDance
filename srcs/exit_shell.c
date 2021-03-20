#include "../incs/minishell.h"

int		exit_shell(t_info *info)
{
	int ret;

	ret = 0;

#if 0
#endif
	ft_lstclear(&(info->set_str_list), &free);
	ft_lstclear(&(info->set_list), &free_set);
	ft_lstclear(&(info->env_list), &free_env);
	if (info->env_list)
	{
		ft_lstclear(&(info->env_list), &free_env);
		free(info->env_list);
		info->env_list = NULL;
	}
	return (ret);
}


