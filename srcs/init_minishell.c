#include "minishell.h"

static void	init_info(
			t_info *info)
{
	t_slist *set_list;
	t_list *env_list;

	set_list = NULL;
	env_list = NULL;
	info->set_list = set_list;
	info->env_list = env_list;
	info->exit = 0;
	info->ret = 0;
}

void		init_minishell(
			t_info *info,
			char **env)
{
	init_info(info);
	process_pre(info, env);
	free_env(&(info->env_list));
}

