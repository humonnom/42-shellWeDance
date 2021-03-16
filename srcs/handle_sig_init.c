#include "../incs/minishell.h"

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
//		if (in process : blocking command)
//			stop process(minishell is still running)
		ft_putstr_fd("\b\b  \n", 2);
		display_prompt();
//		change dollar_ret;
	}
	if (signo == SIGQUIT)
	{
		ft_putstr_fd("\b\b  \n", 2);
	}

}

void		handle_sig_init()
{
	if (signal(SIGINT, (void *)sig_handler) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-C", 2);
	if (signal(SIGQUIT, (void *)sig_handler) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-\\", 2);
	display_prompt();
}
