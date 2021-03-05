#include "../incs/minishell.h"

int	select_sh_bti(t_info *info)
{
	char	*cmd;
	int		ret;

	
	ret = 0;
#if 0
	cmd = info->set->cmd;
	if (!ft_strncmp(cmd, "export"))
		ret = sh_bti_export()
#endif

//cd
//echo
//pwd
//exit
//export
//unset
//env
	return (ret);
}
