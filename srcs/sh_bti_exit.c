/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:10 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:52:22 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

#define EXIT_INVALID_ARG_NUM 1
#define EXIT_NON_NUMERIC_ARG 255

extern int	g_signal;

static int
	is_invalid_number(char *str)
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

void
	print_exit_invalid_case(int invalid_case, int flag_print, char *arg)
{
	if ((invalid_case == EXIT_INVALID_ARG_NUM) && flag_print)
		ft_putstr_fd("exit: too many arguments\n", STDOUT_FILENO);
	else if ((invalid_case == EXIT_NON_NUMERIC_ARG) && flag_print)
	{
		ft_putstr_fd("exit: ", STDOUT_FILENO);
		ft_putstr_fd(arg, STDOUT_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDOUT_FILENO);
	}
	g_signal = invalid_case;
}

int
	sh_bti_exit(char **args, t_info *info, int flag_print)
{
	int	invalid_case;

	invalid_case = 0;
	if (!args)
		exit_shell(info);
	if (args[0] && args[1])
		invalid_case = EXIT_INVALID_ARG_NUM;
	else if (args[0] && is_invalid_number(args[0]))
		invalid_case = EXIT_NON_NUMERIC_ARG;
	if (invalid_case)
	{
		print_exit_invalid_case(invalid_case, flag_print, args[0]);
		return (1);
	}
	g_signal = 0;
	if (args[0])
		g_signal = ft_atoi(args[0]);
	exit_shell(info);
	return (0);
}
