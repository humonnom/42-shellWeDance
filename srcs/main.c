#include "../incs/minishell.h"

#if 1
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
		print_slist(info->set_list);
		// get cmd_arg list
		//parse_set(info->set_list->data);
		//select_func(info->set_list->data);
//		info->set_list = change_head(info->set_list);
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

#endif
int main(int argc, char *argv[], char *env[])
{
#if 1
	(void)argc;
	(void)argv;
	t_info info;

	init_minishell(&info, env);
	if (run(&info))
		return (-1);
	char *line = "e\"ch\'o\'\" \"ab;;;;  c\"; \"c\'\'d\" \";;;..\"";
	printf("line: %s\n", line);
	parse_line(line, &info.set_list);

//	free() return (info->ret)
	free_list(&(info.env_list));
#endif
	return (0);
}
