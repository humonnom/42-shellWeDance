#include "../incs/minishell.h"

t_list	*gen_elist(char **str)
{
	int		error_num;
	int		idx;
	t_env	*tmp_env;
	t_list	*ret;

	ret = NULL;	
	error_num = 0;	
	idx = -1;
	while (error_num == 0 && str[++idx])
	{
		if (!(tmp_env = gen_env(str[idx])))
			error_num = 1;
		ft_lstadd_back(&ret, ft_lstnew(tmp_env));
	}
	return (ret);
}
