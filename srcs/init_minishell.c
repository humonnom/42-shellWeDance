#include "../incs/minishell.h"

static void			init_info(
					t_info *info)
{
	t_slist	*set_list;
	t_elist	*env_list;

	set_list = NULL;
	env_list = NULL;
	info->set_list = set_list;
	info->env_list = env_list;
	info->exit = 0;
	info->ret = 0;
}

//env_list has to be sort with printing.
int					init_minishell
					(t_info *info,
					char **env)
{
	int ret;

	ret = 0;
	init_info(info);
	if (ret == 0)
		ret = get_list(&(info->env_list), env);
	if (ret == 0)
		ret = inc_shlvl(&(info->env_list));
	return (ret);
}
