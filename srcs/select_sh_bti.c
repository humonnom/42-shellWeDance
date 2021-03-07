#include "../incs/minishell.h"

int	select_sh_bti(t_info *info)
{
	char	*cmd;
	char	**args;
	int		ret;

	
	ret = 0;
	cmd = info->set->cmd;
	args = info->set->args;
	if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
		ret = sh_bti_export(args, info);
	if (!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
		ret = sh_bti_unset(args, info);
	if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
		ret = sh_bti_env(info->env_list);

//cd
//echo
//pwd
//exit
//export
//unset
//env
	return (ret);
}
