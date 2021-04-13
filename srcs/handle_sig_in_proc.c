#include "../incs/minishell.h"
extern int	g_signal;

static void	sigint_handler_proc(int signo)
{
	//no need to remove signal
	//stop process(minishell is still running)
	//change dollar_ret;
	g_signal = SIG_SIGINT;
	//g_signal = 130;
	//display prompt
	ft_putstr_fd("^C", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	sigquit_handler_proc(int signo)
{
	//no need to remove signal
	//put messege
	ft_putstr_fd("Quit: 3", STDOUT_FILENO);
	//stop process(minishell is still running)
	//change dollar_ret
	g_signal = SIG_SIGQUIT;
	//g_signal = 131;
	//display prompt
	ft_putstr_fd("\n", STDOUT_FILENO);
}

//when signal pressed in processing.
void		handle_sig_in_proc(int pid)
{
	if (signal(SIGINT, (void *)sigint_handler_proc) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-C", STDOUT_FILENO);
	if (signal(SIGQUIT, (void *)sigquit_handler_proc) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-\\", STDOUT_FILENO);
}

