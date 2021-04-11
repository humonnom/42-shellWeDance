#include "../incs/minishell.h"

extern int g_signal;

static void handle_sigint_in_gnl(int signo)
{
	g_signal = SIG_SIGINT;
	write(STDOUT_FILENO, "\n", 1);
}

static void handle_sigquit_in_gnl(int signo)
{
	g_signal = SIG_SIGINT;
}

void	handle_sig_in_gnl(t_info info, long *inst_arr)
{
	signal(SIGINT, &handle_sigint_in_gnl); 
	//signal(SIGQUIT, SIG_IGN);

	if (g_signal == SIG_SIGINT)
	{
		ft_memset(inst_arr, 0, BUFFER_SIZE);
		write(STDOUT_FILENO, "\n", 1);
	}

	g_signal = OFF;
}
