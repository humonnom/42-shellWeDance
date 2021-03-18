#include "../incs/minishell.h"

//memory free about set
void change_head(t_info *info)
{
	t_list *tmp;

	tmp = (info->set_str_list)->next;
	//free_set(info->set);
	ft_lstdelone(info->set_str_list, &free);
	info->set_str_list = tmp;
}

int run(t_info *info)
{
	char	*line;

	while (info->exit == 0)
	{
		//init_sig();
		if (info->set_str_list == NULL)
		{
			if ((get_next_line(&line)) == -1)
				return -1;
			if (!(info->set_str_list = parse_line(line)))
				return -1;
		}
		info->set_list = parse_set(info->set_str_list->data);
#if 1
		while (info->set_list)
		{
			run_cmd(info->set_list, info->env_list);
			info->set_list = info->set_list->next;
		}
#endif
		ft_lstclear(&(info->set_list), &free_set);
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
