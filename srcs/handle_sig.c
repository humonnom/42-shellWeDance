#include "../incs/minishell.h"

extern int g_signal;

void	handle_sig_in_gnl(t_info *info, long *arr, int *idx, int *buf_len)
{
	if (g_signal == SIG_SIGINT)
	{
		ft_memset(arr, 0, BUFFER_SIZE);
		*buf_len = 0;
		*idx = -1;
		g_signal = OFF;
	}
}

void	handle_eof_in_gnl(t_info *info, long *c, int buf_len)
{
	if (*c == 4 && buf_len == 0)
		exit_shell(info);
	else if (*c == 4 && buf_len != 0)
		*c = 4500001;
}
