#include "../incs/minishell.h"

int categorize_cmd(t_info *info)
{
	int		ret;
	int		idx;
	t_set	*set;

	ret = 0;
	//printf("categorize.c 10=======================\n");
	set = info->set;
	if (!(set->cmd = trim_cmd(set->cmd)))
	{
		printf("ERROR: trim_cmd malloc error\n");
		//printf("categorize.c 15=======================\n");
		return (1);
	}
	//printf("categorize.c 18=======================\n");

	if (select_shell_bti(info))
	{
		printf("ERROR: select_shell_bti error\n");
		//printf("categorize.c 23=======================\n");
		return (-1);
	}
	//printf("categorize.c 27=======================\n");
	if (run_bti(info))
	{
		printf("ERROR: run_bti error\n");
		return (-1);
	}
	//if(bti_path) -> fork
	//else bti_path is NULL -> show error message.
	//after using bti function with execve, free path.
	//arg_beg = arg_list->next;
	//make list to arr function.(arg_beg, env_list)
	//after using arg_beg array, env array, free.(pk_split_free)
	//strncmp(find one)
	return (ret);
}
