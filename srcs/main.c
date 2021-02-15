#include "../incs/minishell.h"

void print_slist(t_slist *set_list) {
	t_slist *obj = set_list;
	while (obj) {
		printf("%s\n", (char *)obj->data->data);
		obj = obj->next;	
	}
}

t_slist *change_head(t_slist *set_list)
{
	t_slist *ret;

	ret = set_list->next;
	//modify pk_lstdelone to delete t_alist
	pk_lstdelone(set_list, &free);
	printf("after head change: %s\n", (char *)ret->data);
	return (ret);
}

int run(t_info *info)
{
	char *line;

	while (info->exit == 0)
	{
		//init_sig();
		if (info->set_list == NULL)
		{
			if ((get_next_line(&line)) == -1)
				return -1;
			// get set list
			if (parse_line(line, &(info->set_list)))
				return -1;
		}
		// get cmd_arg list
		printf("parse_set input: %s\n", (char *)info->set_list->data->data);
		
		parse_set(&(info->set_list->data));
		print_list(info->set_list->data);

//		break;
		//select_func(info->set_list->data);
		info->set_list = info->set_list->next;//change_head(info->set_list);
	}
	return (0);
}

#if 0
select_func(cmd, args) {
	func_built_in
	echo
	cd
	pwd
	..

	func_bin_
	ls
	grep
	...
}
#endif

int main(int argc, char *argv[], char *env[])
{
#if 1
	(void)argc;
	(void)argv;
	int	err_num;
	t_info info;

	err_num = 0;
	init_minishell(&info, env);
	if ((err_num = run(&info)))
	{
		printf("err_num: %d\n", err_num);
		return (-1);
	}
#if 0
	char *line = "e\"ch\'o\'\" \"ab;;;;  c\"; \"c\'\'d\" \";;;..\"";
	printf("line: %s\n", line);
	parse_line(line, &info.set_list);
#endif

//	free() return (info->ret)
	free_list(&(info.env_list));
#endif
	return (0);
}
