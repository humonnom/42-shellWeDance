#include "../incs/minishell.h"

//memory free about set
void change_head(t_info *info)
{
	t_list *tmp;
	int		i;

	ft_lstclear(&(info->set_list), &free_set);
	tmp = (info->set_str_list)->next;
	ft_lstdelone(info->set_str_list, &free);
	info->set_str_list = tmp;

}

int run(t_info *info)
{
	char	*line;
	t_list	*next;

	while (info->exit == 0)
	{
		if (info->set_str_list == NULL)
		{
			display_prompt();
			handle_sig_init(info);
			if ((get_next_line(info, &line)) == -1)
				return -1;
			if (!(info->set_str_list = gen_set_str_list(line)))
				return -1;
			free(line);
		}
		info->set_list = gen_set_list(info);
		//print_slist(info->set_list);
		while (info->set_list)
		{
			int flag = 0;
			run_cmd(info);
			next = info->set_list->next;
			ft_lstdelone(info->set_list, &free_set);
			info->set_list = next;
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
	init_global();
	run(&info);
#if 0
	char *str     = "echo abc >>text.txt args args2";
	char *str_cpy = "echo abc >>text.txt args args2";
	parse_redir(&info, str, str_cpy);


	char *set_str = "echo        abc \"   >>   << \"def>> edf";

	gen_set(&info, set_str);
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
