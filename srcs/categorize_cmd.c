#include "../incs/minishell.h"

int categorize_cmd(t_info *info)
{
	int		ret;
	int		run_check;
	int		idx;

	ret = 1;
	run_check = 0;
	if (del_quote(&(info->set->cmd)))
	{
		printf("ERROR: trim_cmd malloc error\n");
		return (1);
	}
	if (!(ret = select_sh_bti(info)))
		printf("SHELL BUILTIN CASE\n");
	else if (ret && !(ret = run_bti(info)))
		printf("BUILTIN CASE\n");

	return (ret);
}
