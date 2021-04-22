/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:10 by juepark           #+#    #+#             */
/*   Updated: 2021/04/22 14:34:09 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int		g_signal;

static int	is_invalid_number(char *str)
{
	int idx;

	idx = -1;
	while (str[++idx])
		if (!ft_isdigit(str[idx]))	
			return (1);
	return (0);
}

void		sh_bti_exit(char **args, t_info *info)
{
	int	len;

	len = 0;
	if (args[0] && args[1])
	{
		ft_putstr_fd("exit: too many arguments\n", STDOUT_FILENO);
		g_signal = 1;
	}
	else
	{
		if (args[0] && is_invalid_number(args[0]))
		{
			ft_putstr_fd("exit: numeric argument required\n", STDOUT_FILENO);
			g_signal = 255;
		}
		else if(args[0])
			g_signal = ft_atoi(args[0]);
		exit_shell(info);
	}
}
