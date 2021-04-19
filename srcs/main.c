/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */ /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:18:47 by juepark           #+#    #+#             */
/*   Updated: 2021/04/19 16:30:49 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		g_signal;

void change_head(t_info *info)
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

int run(t_info *info)
{
	char	*lines;
	t_list	*next;
	int		flag;

	int fd = open("test_echo.txt", O_RDONLY);
	while (info->exit == 0)
	{
		if (info->line_list == NULL)
		{
			set_signo();
#if 1
			if ((lines = get_next_line_tc(info)) == NULL)
				continue ;
#endif
#if 0
			if (get_next_line(&lines, fd) <= 0)
			{
				exit(0);
				continue ;
			}
#endif
#if 1
			printf("lines: %s\n", lines);
			if (exact_strncmp(lines, "") != 0)
			{
				append_history_list(&(info->history), lines);
				info->history_ptr = info->history;
			}
			else
				continue ;
			info->line_list = gen_line_list(lines);
#endif
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

int main(int argc, char *argv[], char *env[])
{
	int		err_num;
	t_info	info;

	err_num = 0;
	init_minishell(&info, env);
	run(&info);
	exit_shell(&info);
	return (0);
}
