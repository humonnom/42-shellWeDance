#include "../incs/minishell.h"

//memory free about set
void change_head(t_info *info)
{
	t_list *tmp;

	tmp = (info->set_list)->next;
	free_set(info->set);
	// modified lstdelone to free data type -> data 
	ft_lstdelone(info->set_list, &free);
	info->set_list = tmp;
}

int run(t_info *info)
{
	char	*line;
	t_list	*tmp_list;

	while (info->exit == 0)
	{
		//init_sig();
		if (info->set_list == NULL)
		{
			if ((get_next_line(&line)) == -1)
				return -1;
			// get set list
			if (!(info->set_list = parse_line(line)))
				return -1;
		}
		if (!(info->set = parse_set(info->set_list->data)))
		{
			printf("ERROR: info->set is empty!\n");
			return (-1);
		} 
		//print_set(info->set);
		categorize_cmd(info);
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
#if 0 // get_dollar_eval test
	char *test = "$HOME abc";
	char *ret = get_dollar_eval(&test, info.env_list);
	printf("part: %s\n", test);
	printf("ret: %s\n", ret);
#endif

#if 0
	char arg1[100] = "\"abc$HOME $HOMEdef\"\'abc\'";
	char arg1[100] = "\"abc def\"\'abc\'";
	char arg2[100] = "\"abc$HOMEdef\"";
	char *args[2] = {arg1, arg2};
	sh_bti_echo(args, info.env_list);
#endif
	
	
#if 0
	char *set_ex = "test=abcd====\"\"===";
	printf("result: %d\n", export_env(&info.env_list, set_ex));
	print_list(info.env_list);

	if ((err_num = run(&info)))
		return (-1);
	printf("err_num: %d\n", err_num);
#endif

	//need to make free_slist, free_alist
	//free_all_elist(&(info.env_list));
	return (0);
}
