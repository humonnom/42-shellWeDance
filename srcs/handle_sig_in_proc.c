/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig_in_proc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:56 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:18:11 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"
extern int	g_signal;

static void	sigint_handler_proc(int signo)
{
	g_signal = SIG_SIGINT;
	ft_putstr_fd("^C", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	sigquit_handler_proc(int signo)
{
	ft_putstr_fd("Quit: 3", STDOUT_FILENO);
	g_signal = SIG_SIGQUIT;
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

