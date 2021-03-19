#include "../incs/minishell.h"

int categorize_cmd(t_set *set, t_list **env_list)
{
	int		ret;
	int		run_check;
	int		idx;

	ret = 1;
	run_check = 0;
	if (del_quote(&(set->cmd)))
	{
		printf("ERROR: trim_cmd malloc error\n");
		return (1);
	}
	if (!(ret = select_sh_bti(set, env_list)))
		printf("SHELL BUILTIN CASE\n");
	else if (ret && !(ret = run_bti(set, *env_list)))
		printf("BUILTIN CASE\n");
	else
		printf("zsh: command not found: %s\n", set->cmd);
	return (ret);
}
