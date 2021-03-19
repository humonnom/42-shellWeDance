#include "../incs/minishell.h"

int	redo_sh_bti(t_set *set, t_info *info)
{
	char	*cmd;
	char	**args;
	int		ret;
	int		cmp_len;
	
	ret = 1;
	cmd = set->cmd;
	args = set->args;
	if (!exact_strncmp(cmd, "export"))
		ret = sh_bti_export(args, &(info->env_list));
	else if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_unset(args, &(info->env_list));
	else if (!exact_strncmp(cmd, "cd"))
		ret = sh_bti_cd(args, info->env_list);
	else if (!exact_strncmp(cmd, "exit"))
		ret = sh_bti_exit(info);
	else
		ret = 0;
	return (ret);
}
