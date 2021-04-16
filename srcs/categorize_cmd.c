/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:33 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 21:25:31 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

static void	turn_on_echo(t_info *info)
{
	info->tc.term.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &(info->tc.term));
}

int categorize_cmd(t_tokens *tokens, t_info *info)
{
	int		ret;
	int		run_check;
	int		idx;

	ret = 1;
	run_check = 0;
	if (del_quote(&(tokens->cmd)))
	{
		printf("ERROR: trim_cmd malloc error\n");
		g_signal = 1;
		return (1);
	}
	ret = select_sh_bti(tokens, info);
	if (ret) 
	{
		turn_on_echo(info);
		ret = run_bti(tokens, info->env_list);
	}
	if (ret)
	{
		printf("command not found: %s\n", tokens->cmd);
		g_signal = 127;
	}
	return (ret);
}
