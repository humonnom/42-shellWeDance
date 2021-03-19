#include "../incs/minishell.h"

void	handle_eof(t_info *info, char *backup)
{
	if (ft_strlen(backup) == 0)
	{
		free(backup);
		g_ret = 0;
		g_ret = exit_shell(info);
		exit(0);
	}
	else
		ft_putstr_fd("  \b\b", STDERR);
}
