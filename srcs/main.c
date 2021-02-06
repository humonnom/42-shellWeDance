#include "minishell.h"

t_slist *change_head(t_slist *set_list)
{
	t_list *ret;

	ret = set_list->next;
	//modify pk_lstdelone to delete t_alist
	pk_lstdelone(set_list, &free);
	return (ret);
}

int run(t_info *info)
{
	char *line;

	while (info->exit ==)
	{
		init_sig();
		if (set_list == NULL)
		{
			if ((get_next_line(&line)) == -1)
				return -1;
			// get set list
			if (parse_line(line, info->set_list))
				return -1;
		}
		// get cmd_arg list
		parse_set(info->set_list->data);
		select_func(info->set_list->data);
		change_head(info->set_list);
	}
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
	t_info info;

	init_minishell(info, env);
	if (run(&info))
		return (-1);
	free() return (info->ret)
}
