/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:33 by juepark           #+#    #+#             */
/*   Updated: 2021/04/24 00:15:06 by jackjoo          ###   ########.fr       */
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
	int		err_num;

	err_num = select_sh_bti(tokens, info);
	if (err_num == ERR_NOT_FOUND)
	{
		turn_on_tc_setting(info);
		err_num = run_bti(tokens, info->env_list);
	}
	if (err_num == ERR_BTI)
		g_signal = 1;
	if (err_num == ERR_NOT_FOUND)
	{
		printf("%s :command not found\n", tokens->cmd);
		g_signal = 127;
		return (1);
	}
	if (err_num == ERR_SH_BTI || err_num == ERR_BTI)
		return (1);
	return (0);
}
