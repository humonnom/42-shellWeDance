/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:52 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 13:17:56 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int	g_signal;

static void
	set_sigint(int signo)
{
	g_signal = SIG_SIGINT;
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putstr_fd(PROMPT_DATA, STDOUT_FILENO);
}

static void
	set_sigquit(int signo)
{
	(void)signo;
}

int
	set_signo()
{
	signal(SIGINT, &set_sigint);
	signal(SIGQUIT, &set_sigquit);
	return (0);
}
