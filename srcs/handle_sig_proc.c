#include "../incs/minishell.h"

static void	sig_handler_proc(int signo)
{
	if (signo == SIGINT)
	{
		//no need to remove signal
		//stop process(minishell is still running)
		
		//change dollar_ret;
		
		//display prompt
		ft_putstr_fd("\n", 2);
		display_prompt();
	}
	if (signo == SIGQUIT)
	{
		//no need to remove signal
		//put messege
		ft_putstr_fd("Quit: 3", 2);
		
		//stop process(minishell is still running)
		
		//change dollar_ret
		
		//display prompt
		ft_putstr_fd("\n", 2);
		display_prompt();
	}

}
//when signal pressed in processing.
void		handle_sig_proc(int pid)
{
	if (signal(SIGINT, (void *)sig_handler_proc) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-C", 2);
	if (signal(SIGQUIT, (void *)sig_handler_proc) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-\\", 2);
	display_prompt();
}
