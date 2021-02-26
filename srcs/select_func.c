#include "../incs/minishell.h"

int select_func(t_list *arg_list)
{
	int	ret;

	ret = 0;
	if (!(trim_cmd(arg_list)))
		ret = 1;
	return (ret);
}
