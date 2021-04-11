#include "../incs/minishell.h"

static void	sigint_handler_proc(int signo)
{
	//no need to remove signal
	//stop process(minishell is still running)
	//change dollar_ret;
	g_ret = 130;
	//display prompt
	ft_putstr_fd("\n", STDERR_FILENO);
}

static void	sigquit_handler_proc(int signo)
{
	//no need to remove signal
	//put messege
	ft_putstr_fd("Quit: 3", STDERR_FILENO);
	//stop process(minishell is still running)
	//change dollar_ret
	g_ret = 131;
	//display prompt
	ft_putstr_fd("\n", STDERR_FILENO);
}

//when signal pressed in processing.
void		handle_sig_proc(int pid)
{
	if (signal(SIGINT, (void *)sigint_handler_proc) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-C", STDERR_FILENO);
	if (signal(SIGQUIT, (void *)sigquit_handler_proc) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-\\", STDERR_FILENO);
}
