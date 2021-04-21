/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:33 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 11:42:45 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

static void
	turn_on_echo(t_info *info)
{
	info->tc.term.c_lflag |= ECHO;
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
		turn_on_echo(info);
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
