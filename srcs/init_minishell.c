#include "minishell.h"

init_env()
{
	make_lst();
}

static void process_pre(t_info *info, char **env)
{
	//1.
	init_env(info);
	//env -> info->env_lst

	//2.
	//create function for making lst
	//find index of wanted data in env_lst

	//3.
	inc_shell_level(info);
	//find shlvl -> increse value
}

static void init_info(t_info *info)
{
	info->set_lst = NULL;
	info->set_lst->data = NULL;
}

void init_minishell(t_info *info, char **env)
{
	init_info(info);
	process_pre(info, env);
}
