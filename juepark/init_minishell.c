#include "minishell.h"

static void			init_info(
					t_info *info)
{
	t_slist	*set_list;
	t_list	*env_list;

	set_list = NULL;
	env_list = NULL;
	info->set_list = set_list;
	info->env_list = env_list;
	info->old_pwd = ft_strdup("");
	info->exit = 0;
	info->ret = 0;
}

int					init_minishell
					(t_info *info,
					char **env)
{
	int ret;

	ret = 0;
	init_info(info);
	if (ret == 0)
		ret = process_pre(&(info->env_list), env);
	return (ret);
}
