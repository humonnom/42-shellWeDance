#include "../incs/minishell.h"

extern int g_signal;

static void handle_sigint_in_gnl(int signo)
{
	g_signal = SIG_SIGINT;
	//prompt >> 
}

static void handle_sigquit_in_gnl(int signo)
{
	g_signal = SIG_SIGQUIT;
}

void	handle_sig_in_gnl()
{
	signal(SIGINT, &handle_sigint_in_gnl); 
	signal(SIGQUIT, &handle_sigquit_in_gnl); 
}
