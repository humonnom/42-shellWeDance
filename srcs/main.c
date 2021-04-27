/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:18:47 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:40:06 by juepark          ###   ########.fr       */
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

static void
	run_tokens(t_info *info)
{
	t_list	*next_tokens;

	info->tokens_list = gen_tokens_list(info);
	while (info->tokens_list)
	{
		run_cmd(info);
		next_tokens = info->tokens_list->next;
		ft_lstdelone(info->tokens_list, &free_tokens);
		info->tokens_list = next_tokens;
	}
}

int
	run(t_info *info)
{
	char	*lines;

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
		run_tokens(info);
		change_head(info);
	}
	return (0);
}

int
	main(int argc, char *argv[], char *env[])
{
	int		err_num;
	t_info	info;

	(void)argc;
	(void)argv;
	err_num = 0;
	init_minishell(&info, env);
	run(&info);
	sh_bti_exit(NULL, &info, FLAG_PRINT_OFF);
	return (0);
}
