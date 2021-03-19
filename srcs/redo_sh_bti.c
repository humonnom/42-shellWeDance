#include "../incs/minishell.h"

int	redo_sh_bti(t_set *set, t_list **env_list)
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
	else if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_unset(args, env_list);
	else
		ret = 0;
	return (ret);
}
