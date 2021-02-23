#include "../incs/minishell.h"

#if 0
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
	(void)argc;
	(void)argv;
	int	err_num;
	t_info info;

	err_num = 0;
	init_minishell(&info, env);
	print_elist(info.env_list);
#if 0
	char *set_ex = "test=abcd====\"\"===";
	printf("result: %d\n", export_env(&info.env_list, set_ex));
	print_list(info.env_list);

	if ((err_num = run(&info)))
		return (-1);
	printf("err_num: %d\n", err_num);
#endif

//	free() return (info->ret)
	free_elist(&(info.env_list));
	while (1)
		;
	return (0);
}
