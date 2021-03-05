#include "../incs/minishell.h"

int	select_sh_bti(t_info *info)
{
	char	*cmd;
	char	**args;
	int		ret;

	
	ret = 0;
	cmd = info->set->cmd;
	args = info->set->args;
//	if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
//		ret = sh_bti_export(args, info->env_list);
//	if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
//		ret = sh_bti_env(info->env_list);
	if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
		ret = sh_bti_cd(args, info->env_list);
	if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
		ret = sh_bti_pwd();

//cd
//echo
//pwd
//exit
//export
//unset
//env
	return (ret);
}
