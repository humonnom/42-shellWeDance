#include "../incs/minishell.h"

//memory free about set
void change_head(t_info *info)
{
	t_list *tmp;

	//=========== ft_lstclear(arg_list, &free);
	
	tmp = (info->set_list)->next;
	free_set(info->set);
	//modify pk_lstdelone to delete t_alist
	ft_lstdelone(info->set_list, &free);
	info->set_list = tmp;
}

#if 1
int run(t_info *info)
{
	char	*line;
	t_list	*tmp_list;
	char	*func_path;
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
		// print sets
		//printf("%s\n", (char *)(info->set_list->data));
#if 0
		if (!(info->arg_list = parse_set(info->set_list->data)))
			return (-1);
#endif
		//=========== print_alist(info->arg_list);
		if (!(info->set = parse_set_arr(info->set_list->data)))
		{
			printf("ERROR: info->set is empty!\n");
			return (-1);
		} 
		print_set(info->set);
		if (!(func_path = get_eval(info->env_list, "PATH")))
			printf("ERROR: func_path is NULL\n");
		//=========== select_func(info->arg_list, func_path);
		select_func(info->set, func_path);
		change_head(info);
	}
	return (0);
}
#endif

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
	char *set_ex = "test=abcd====\"\"===";
	printf("result: %d\n", export_env(&info.env_list, set_ex));
	print_list(info.env_list);

	if ((err_num = run(&info)))
		return (-1);
	printf("err_num: %d\n", err_num);
#endif

	//need to make free_slist, free_alist
	free_elist(&(info.env_list));
	return (0);
}
