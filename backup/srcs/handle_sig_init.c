#include "../incs/minishell.h"

static void	sigint_handler(int signo)
{
	//remove signal, and change line
	ft_putstr_fd("\b\b  \n", STDERR);
//	display_prompt();
	//change dollar_ret
	g_ret = 130;
	g_fsh_buf = 1;
}

static void	sigquit_handler(int signo)
{
  	//remove signal(nothing to change on the screen)
  	ft_putstr_fd("\b\b  \b\b", STDERR);
  	//do nothing
	//no change dollar_ret
}

void		handle_sig_init(t_info *info)
{
	if (signal(SIGINT, (void *)sigint_handler) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-C", 2);
	if (signal(SIGQUIT, (void *)sigquit_handler) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-\\", 2);
}
