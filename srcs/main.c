#include "../incs/minishell.h"

void change_head(t_list **set_list)
{
	t_list *tmp;

	tmp = (*set_list)->next;
	//modify pk_lstdelone to delete t_alist
	ft_lstdelone(*set_list, &free);
	*set_list = tmp;
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
			if (!(info->set_list = parse_line(line)))
				return -1;
		}

		// print sets
		printf("%s\n", (char *)(info->set_list->data));
//		parse_set(&(info->set_list->data));
		#if 0
		//select_func(info->set_list->data);
		info->set_list = info->set_list->next;
		#endif
//		info->set_list = change_head(info->set_list);
		change_head(&(info->set_list));
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
