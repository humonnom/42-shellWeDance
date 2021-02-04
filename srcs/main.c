#include "minishell.h"

t_lst *change_head(t_lst *set_lst)
{
	t_lst *ret;

	ret = set_lst->next;
	//modify pk_lstdelone to delete t_alst
	pk_lstdelone(set_lst, &free);
	return (ret);
}

int run(t_info *info)
{
	char *line;

	while (info->exit ==)
	{
		init_sig();
		if (set_lst == NULL)
		{
			if ((get_next_line(&line)) == -1)
				return -1;
			// get set list
			if (parse_line(line, info->set_lst))
				return -1;
		}
		// get cmd_arg list
		parse_set(info->set_lst->data);
		select_func(info->set_lst->data);
		change_head(info->set_lst);
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
