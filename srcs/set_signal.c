#include "../incs/minishell.h"

extern int g_signal;

static void set_sigint(int signo)
{
	g_signal = SIG_SIGINT;
}

static void set_sigquit(int signo)
{
	g_signal = SIG_SIGQUIT;
}

void	set_signal()
{
	g_signal = OFF;
	signal(SIGINT, &set_sigint); 
	signal(SIGQUIT, &set_sigquit); 
}
