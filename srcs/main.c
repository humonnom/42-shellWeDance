#include "../incs/minishell.h"

int		g_signal;

void change_head(t_info *info)
{
	t_list	*tmp;
	int		i;

	ft_lstclear(&(info->tokens_list), &free_tokens);
	tmp = (info->line_list)->next;
	ft_lstdelone(info->line_list, &free);
	info->line_list = tmp;
}

int run(t_info *info)
{
	char	*lines;
	t_list	*next;

	while (info->exit == 0)
	{
		if (info->line_list == NULL)
		{
			//handle_sig();
			if ((lines = get_next_line_tc(info)) == NULL)
				continue ;
			if (exact_strncmp(lines, "") != 0)
			{
				append_history_list(&(info->history), lines);
				info->history_ptr = info->history;
			}
			else
				continue ;
			if (!(info->line_list = gen_line_list(lines)))
				return -1;
		}
		info->tokens_list = gen_tokens_list(info);
		while (info->tokens_list)
		{
			int flag = 0;
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
