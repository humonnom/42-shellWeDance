#include "../incs/minishell.h"

int		g_signal;

void change_head(t_info *info)
{
	t_list	*tmp;

	if (info->line_list != NULL)
	{
		tmp = (info->line_list)->next;
		ft_lstdelone(info->line_list, &free);
		//ft_lstclear(&(info->tokens_list), &free_tokens);
		info->line_list = tmp;
	}
}

static void	turn_off_echo(t_info *info)
{
	info->tc.term.c_lflag &= (~ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &(info->tc.term));
}

int run(t_info *info)
{
	char	*lines;
	t_list	*next;

	while (info->exit == 0)
	{
		if (info->line_list == NULL)
		{
			set_signo();
			// user inpt: ls -al; pwd; cd ..;
			if ((lines = get_next_line_tc(info)) == NULL)
				continue ;
			// lines: ls -al; pwd; cd ..;
			if (exact_strncmp(lines, "") != 0)
			{
				append_history_list(&(info->history), lines);
				info->history_ptr = info->history;
			}
			else
				continue ;
			// line_list: ls -al -> pwd -> cd ..
			info->line_list = gen_line_list(lines);
		}
		//printf("line_list->data: %s\n", (char *)info->line_list->data);
		info->tokens_list = gen_tokens_list(info);
		while (info->tokens_list)
		{
			int flag = 0;
			run_cmd(info);
#if 0
			t_tokens *tokens = (t_tokens *)info->tokens_list->data;
			printf("	cmd: %s\n", (char *)tokens->cmd);
			int idx;
			idx = -1;
			while (tokens->args[++idx])
				printf("	arg: %s\n", (char *)tokens->args[idx]);
#endif
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
