/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:52 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:47:10 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

void	handle_sig_in_gnl(t_info *info, long *arr, int *idx, int *buf_len)
{
	(void)info;
	if (g_signal == SIG_SIGINT)
	{
		ft_memset(arr, 0, BUFFER_SIZE);
		*buf_len = 0;
		*idx = -1;
		g_signal = 1;
	}
}

void	handle_eof_in_gnl(t_info *info, long *c, int buf_len)
{
	if (*c == 4 && buf_len == 0)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		sh_bti_exit(NULL, info, FLAG_PRINT_OFF);
	}
	else if (*c == 4 && buf_len != 0)
		*c = 4500001;
}
