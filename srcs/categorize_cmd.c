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
		ft_putstr_fd("[SHELL BUILTIN CASE]\n", STDERR);
	else if (ret && !(ret = run_bti(info)))
		ft_putstr_fd("[BUILTIN CASE]\n", STDERR);
	else
		printf("zsh: command not found: %s\n", info->set->cmd);
	return (ret);
}
