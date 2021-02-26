#include "../incs/minishell.h"

static void			init_info(
					t_info *info)
{
	info->set_list = NULL;
	info->env_list = NULL;
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
		ret = gen_elist(&(info->env_list), env);
	if (ret == 0)
		ret = inc_shlvl(&(info->env_list));
//	print_elist(info->env_list);
	return (ret);
}
