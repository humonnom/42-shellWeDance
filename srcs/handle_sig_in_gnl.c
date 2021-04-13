#include "../incs/minishell.h"

extern int g_signal;

static void handle_sigint_in_gnl(int signo)
{
	g_signal = SIG_SIGINT;
<<<<<<< HEAD
	write(STDOUT_FILENO, "\n", 1);
=======
	//prompt >> 
>>>>>>> df52ce4be677ec57d998a3f41ac1db1c54c05c33
}

static void handle_sigquit_in_gnl(int signo)
{
<<<<<<< HEAD
	g_signal = SIG_SIGINT;
}

void	handle_sig_in_gnl(t_info info, long *inst_arr)
{
	signal(SIGINT, &handle_sigint_in_gnl); 
	//signal(SIGQUIT, SIG_IGN);

#if 0
	if (g_signal == SIG_SIGINT)
	{
		ft_memset(inst_arr, 0, BUFFER_SIZE);
		write(STDOUT_FILENO, "\n", 1);
	}
#endif

	g_signal = OFF;
=======
	g_signal = SIG_SIGQUIT;
}

void	handle_sig_in_gnl()
{
	signal(SIGINT, &handle_sigint_in_gnl); 
	signal(SIGQUIT, &handle_sigquit_in_gnl); 
>>>>>>> df52ce4be677ec57d998a3f41ac1db1c54c05c33
}
