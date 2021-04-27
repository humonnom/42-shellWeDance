/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig_in_proc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:56 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:48:24 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int	g_signal;

static void	sigint_handler_proc(int signo)
{
	(void)signo;
	g_signal = RET_SIGINT;
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static void	sigquit_handler_proc(int signo)
{
	(void)signo;
	g_signal = RET_SIGQUIT;
	ft_putstr_fd("Quit: 3", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void		handle_sig_in_proc(void)
{
	if (signal(SIGINT, (void *)sigint_handler_proc) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-C", STDOUT_FILENO);
	if (signal(SIGQUIT, (void *)sigquit_handler_proc) == SIG_ERR)
		ft_putstr_fd("\n\e[1;31m can't catch cnrtl-\\", STDOUT_FILENO);
}
