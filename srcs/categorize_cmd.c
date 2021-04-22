/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:33 by juepark           #+#    #+#             */
/*   Updated: 2021/04/22 13:51:27 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

static void
	turn_on_tc_setting(t_info *info)
{
	info->tc.term.c_lflag |= ECHO;
	info->tc.term.c_lflag |= ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &(info->tc.term));
}

int
	categorize_cmd(t_tokens *tokens, t_info *info)
{
	int		ret;
	int		run_check;
	int		idx;

	run_check = 0;
	ret = select_sh_bti(tokens, info);
	if (ret == ERR_NOT_FOUND)
	{
		turn_on_tc_setting(info);
		ret = run_bti(tokens, info->env_list);
	}
	if (ret == ERR_NOT_FOUND)
	{
		printf("%s :command not found\n", tokens->cmd);
		g_signal = 127;
	}
	if (ret == ERR_SH_BTI || ret == ERR_BTI)
		printf("ERROR BTI\n");
	return (ret);
}
