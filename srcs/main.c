#include "../incs/minishell.h"
t_list *change_head(t_list *set_list)
{
	t_list *ret;

	ret = set_list->next;
	//modify pk_lstdelone to delete t_alist
	//printf("DEBUG1=============================\n");
	ft_lstdelone(set_list, &free);
	//printf("DEBUG2=============================\n");
	return (ret);
}

#if 1
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
		#if 0
		// get cmd_arg list
		printf("parse_set input: %s\n", (char *)info->set_list->data->data);
		
		parse_set(&(info->set_list->data));
		print_list(info->set_list->data);

//		break;
		//select_func(info->set_list->data);
		info->set_list = info->set_list->next;
		#endif
		printf("%s\n", (char *)(info->set_list->data));
		info->set_list = change_head(info->set_list);
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

	free_elist(&(info.env_list));
	return (0);
}
