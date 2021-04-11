#include "../incs/minishell.h" //memory free about tokens

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
			//handle_sig_init(info);
			if ((lines = get_next_line_tc(info)) == NULL)
				return -1;
			if (exact_strncmp(lines, "") != 0)
			{
				append_history_list(&(info->history), lines);
				info->history_ptr = info->history;
			}
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
	(void)argc;
	(void)argv;
	int	err_num;
	t_info info;

	err_num = 0;
	init_minishell(&info, env);
	run(&info);

#if 0
	t_prompt	prompt;
	prompt.data = ">> ";//shell💃we🕺dance===> 
	prompt.size = ft_strlen(prompt.data);
	info.prompt = prompt;
	//test(&info, prompt);

	char	*line;
	char	*tmp;
	while (1)
	{
		if ((line = get_next_line_tc(&info)) == NULL)
		{
			printf("EMPTY LINE======================================\n");
			break ;
		}
		if (exact_strncmp(line,"") != 0)
		{
			append_history_list(&(info.history), line);
			info.history_ptr = info.history;
		}
	}
#endif
#if 0
	char *str     = "echo abc >>text.txt args args2";
	char *str_cpy = "echo abc >>text.txt args args2";
	parse_redir(&info, str, str_cpy);


	char *set_str = "echo        abc \"   >>   << \"def>> edf";

	gen_tokens(&info, set_str);
#endif

#if 0
	int idx_inc = 0;
	char *str = "    test.txt  >> test2.txt";
	int res = is_valid_fd(str, &idx_inc, TYPE_REIN);
	printf("result of idx_inc: %d\n", idx_inc);
	printf("rest string:   %s\n", &str[idx_inc]);
	printf("result of res: %d\n", res);
#endif

#if 0
	char *str = " echo abc >>   test.txt    >> test2.txt defg hi";
	t_tokens *res = gen_tokens(&info, str);
	//print_tokens(res);

#endif
	exit_shell(&info);
	return (0);
}

#if 0 // get_dollar_eval test
	char *test = "$HOME abc";
	char *ret = get_dollar_eval(&test, info.env_list);
	printf("part: %s\n", test);
	printf("ret: %s\n", ret);
#endif

#if 0
	char arg1[100] = "\"abc$HOME $HOMEdef\"\'abc\'efg";
	//char arg1[100] = "\"abc$HOME $HOMEdef\"\'ghi\'";
	//char arg1[100] = "\"abc def\"\'abc\'";
	char arg2[100] = "\"abc$HOMEdef\"";
	char *args[2] = {arg1, arg2};
	sh_bti_echo(args, info.env_list);
#endif
	
#if 0
	char arg1[100] = "\"-\"";
	char arg2[100] = "\"abc$HOME $HOMEdef\"\'ghi\'";
	char arg3[100] = "\"abc def\"\'abc\'";
	char *args[2] = {NULL, NULL};
	sh_bti_cd(args, info.env_list);
#endif
	
#if 0
	char *set_ex = "test=abcd====\"\"===";
	printf("result: %d\n", export_env(&info.env_list, set_ex));
	print_list(info.env_list);

	if ((err_num = run(&info)))
		return (-1);
	printf("err_num: %d\n", err_num);
#endif
