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
	if (!ft_strncmp(cmd, "export", get_max_strlen(cmd, "export")))
		ret = sh_bti_export(args, info);
	if (!ft_strncmp(cmd, "unset", get_max_strlen(cmd, "unset")))
		ret = sh_bti_unset(args, info);
	if (!ft_strncmp(cmd, "env", get_max_strlen(cmd, "env")))
		ret = sh_bti_env(info->env_list);
	if (!ft_strncmp(cmd, "cd", get_max_strlen(cmd, "cd")))
		ret = sh_bti_cd(args, info->env_list);
	if (!ft_strncmp(cmd, "pwd", get_max_strlen(cmd, "pwd")))
		ret = sh_bti_pwd(args);
	if (!ft_strncmp(cmd, "echo", get_max_strlen(cmd, "echo")))
		ret = sh_bti_echo(args, info->env_list);
//exit
//unset
	return (ret);
}
