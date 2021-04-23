/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:18:47 by juepark           #+#    #+#             */
/*   Updated: 2021/04/23 14:09:32 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		g_signal;

void
	change_head(t_info *info)
{
	t_list	*tmp;

	if (info->line_list != NULL)
	{
		tmp = (info->line_list)->next;
		ft_lstdelone(info->line_list, &free);
		ft_lstclear(&(info->tokens_list), &free_tokens);
		info->line_list = tmp;
	}
}

int
	run(t_info *info)
{
	char	*lines;
	t_list	*next;
	int		flag;

	while (info->exit == 0)
	{
		if (info->line_list == NULL)
		{
			set_signo();
			if ((lines = get_next_line_tc(info)) == NULL)
				continue ;
			if (exact_strncmp(lines, "") != 0)
			{
				append_history_list(&(info->history), lines);
				info->history_ptr = info->history;
			}
			else
				continue ;
			info->line_list = gen_line_list(lines);
			if (info->line_list == NULL)
				continue ;
		}
		info->tokens_list = gen_tokens_list(info);
		while (info->tokens_list)
		{
			flag = 0;
			run_cmd(info);
			next = info->tokens_list->next;
			ft_lstdelone(info->tokens_list, &free_tokens);
			info->tokens_list = next;
		}
		change_head(info);
	}
	return (0);
}

int
	main(int argc, char *argv[], char *env[])
{
	int		err_num;
	t_info	info;

	err_num = 0;
	init_minishell(&info, env);
	run(&info);
	sh_bti_exit(NULL, &info);
	return (0);
}
