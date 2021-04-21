/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:18:26 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 14:11:14 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int	g_signal;

t_tc
	gen_tc(void)
{
	t_tc	ret;

	tcgetattr(STDIN_FILENO, &(ret.term));
	ret.term.c_lflag &= ~ICANON;
	ret.term.c_lflag &= ~ECHO;
	ret.term.c_cc[VMIN] = 1;
	ret.term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &(ret.term));
	ret.cursor.row = 0;
	ret.cursor.col = 0;
	tgetent(NULL, "xterm");
	ret.tc_str[TC_CM] = tgetstr("cm", NULL);
	ret.tc_str[TC_DL] = tgetstr("dl", NULL);
	ret.tc_str[TC_CE] = tgetstr("ce", NULL);
	return (ret);
}

static void
	init_info(
	t_info *info)
{
	info->tokens_list = NULL;
	info->line_list = NULL;
	info->env_list = NULL;
	info->exit = 0;
	info->ret = 0;
	info->history = NULL;
	ft_lstadd_front(&(info->history), ft_lstnew(ft_strdup("")));
	ft_lstadd_front(&(info->history), ft_lstnew(ft_strdup("")));
	info->history_ptr = info->history;
	info->tc = gen_tc();
}

int
	init_minishell
	(t_info *info,
	char **env)
{
	int ret;

	ret = 0;
	g_signal = OFF;
	init_info(info);
	if (ret == 0)
		if (!(info->env_list = gen_elist(env)))
			ret = 1;
	if (ret == 0)
		ret = inc_shlvl(&(info->env_list));
	return (ret);
}
