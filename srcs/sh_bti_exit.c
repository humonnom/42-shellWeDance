/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:10 by juepark           #+#    #+#             */
/*   Updated: 2021/04/20 15:36:54 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int		g_signal;

void	sh_bti_exit(char **args, t_info *info)
{
	int	len;

	len = 0;
	if (args[0] && args[1])
		ft_putstr_fd("exit: too many arguments\n", STDOUT_FILENO);
	else
	{
		if (args[0])
			g_signal = ft_atoi(args[0]);
		exit_shell(info);
	}
}
