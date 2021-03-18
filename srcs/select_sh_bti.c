#include "../incs/minishell.h"

int	select_sh_bti(t_info *info)
{
	char	*cmd;
	char	**args;
	int		ret;
	int		cmp_len;
	
	ret = 1;
	cmd = info->set->cmd;
	args = info->set->args;
	if (!exact_strncmp(cmd, "export"))
		ret = sh_bti_export(args, info);
	if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_unset(args, info);
	if (!exact_strncmp(cmd, "env"))
		ret = sh_bti_env(info->env_list);
	if (!exact_strncmp(cmd, "cd"))
		ret = sh_bti_cd(args, info->env_list);
	if (!exact_strncmp(cmd, "pwd"))
		ret = sh_bti_pwd(args);
	if (!exact_strncmp(cmd, "echo"))
		ret = sh_bti_echo(args, info->env_list);
//exit
//unset
	return (ret);
}
