#include "../incs/minishell.h"

int	select_sh_bti(t_tokens *tokens, t_info *info)
{
	char	*cmd;
	char	**args;
	int		ret;
	
	ret = 1;
	cmd = tokens->cmd;
	args = tokens->args;
	if (!exact_strncmp(cmd, "export"))
		ret = sh_bti_export(args, &(info->env_list));
	if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_unset(args, &(info->env_list));
	if (!exact_strncmp(cmd, "env"))
		ret = sh_bti_env(info->env_list);
	if (!exact_strncmp(cmd, "cd"))
		ret = sh_bti_cd(args, info->env_list);
	if (!exact_strncmp(cmd, "pwd"))
		ret = sh_bti_pwd(args);
	if (!exact_strncmp(cmd, "echo"))
		ret = sh_bti_echo(args, info->env_list);
	if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_echo(args, info->env_list);
	if (!exact_strncmp(cmd, "exit"))
		sh_bti_exit(info);
	return (ret);
}
