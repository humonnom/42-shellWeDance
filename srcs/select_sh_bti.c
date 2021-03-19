#include "../incs/minishell.h"

int	select_sh_bti(t_set *set, t_list **env_list)
{
	char	*cmd;
	char	**args;
	int		ret;
	int		cmp_len;
	
	ret = 1;
	cmd = set->cmd;
	args = set->args;
	if (!exact_strncmp(cmd, "export"))
		ret = sh_bti_export(args, env_list);
	if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_unset(args, env_list);
	if (!exact_strncmp(cmd, "env"))
		ret = sh_bti_env(*env_list);
	if (!exact_strncmp(cmd, "cd"))
		ret = sh_bti_cd(args, *env_list);
	if (!exact_strncmp(cmd, "pwd"))
		ret = sh_bti_pwd(args);
	if (!exact_strncmp(cmd, "echo"))
		ret = sh_bti_echo(args, *env_list);
	if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_echo(args, *env_list);
//	if (!exact_strncmp(cmd, "exit"))
//		ret = sh_bti_echo(info);
	return (ret);
//exit
//unset
}
