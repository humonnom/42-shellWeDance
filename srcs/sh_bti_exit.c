/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:10 by juepark           #+#    #+#             */
/*   Updated: 2021/04/23 16:50:12 by jackjoo          ###   ########.fr       */
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

static void
	exit_shell(t_info *info)
{
	int ret;
	int i;

	if (info->tokens)
	{
		close_tokens_fds(info->tokens);
		info->tokens = NULL;
	}
	ft_lstclear(&(info->line_list), &free);
	ft_lstclear(&(info->tokens_list), &free_tokens);
	ft_lstclear(&(info->env_list), &free_env);
	ft_lstclear(&(info->history), &free);
	if (info->env_list)
	{
		ft_lstclear(&(info->env_list), &free_env);
		free(info->env_list);
		info->env_list = NULL;
	}
	exit(g_signal);
}

int		sh_bti_exit(char **args, t_info *info, int flag_print)
{
	int	len;

	if (!args)
		exit_shell(info);
	len = 0;
	if (args[0] && args[1])
	{
		if (flag_print)
			ft_putstr_fd("exit: too many arguments\n", STDOUT_FILENO);
		g_signal = 1;
	}
	else
	{
		if (args[0] && is_invalid_number(args[0]))
		{
			if (flag_print)
				ft_putstr_fd("exit: numeric argument required\n", STDOUT_FILENO);
			g_signal = 255;
		}
		else if (args[0])
			g_signal = ft_atoi(args[0]);
		else
			g_signal = 0;
		exit_shell(info);
	}
	if (g_signal)
		return (1);
	return (0);
}
