#include "../incs/minishell.h"

static void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		//remove signal, and change line
		ft_putstr_fd("\b\b  \n", 2);
		display_prompt();
		//change dollar_ret;
	}
	if (signo == SIGQUIT)
	{
		//remove signal(nothing to change on the screen)
		ft_putstr_fd("\b\b  \b\b", 1);
		//do nothing
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
