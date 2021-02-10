#include "minishell.h"

static void	init_env()
{
	make_list();
}

static void process_pre(t_info *info, char **env)
{
	//1.
	init_env(info);
	//env -> info->env_list

	//2.
	//create function for making list
	//find index of wanted data in env_list

	//3.
	inc_shell_level(info);
	//find shlvl -> increse value
}

static void init_info(t_info *info)
{
	info->set_list = NULL;
	info->set_list->data = NULL;
}

void init_minishell(t_info *info, char **env)
{
	init_info(info);
	process_pre(info, env);
}
