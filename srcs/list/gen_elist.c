#include "../../incs/minishell.h"

int	gen_elist(
	t_list **list_head,
	char **str)
{
	int		ret;
	int		idx;
	t_env	*tmp_env;

	ret = 0;	
	idx = -1;
	while (ret == 0 && str[++idx])
	{
		if (!(tmp_env = parse_env(str[idx])))
			ret= 1;
		ft_lstadd_back(list_head, ft_lstnew(tmp_env));
	}
	return (ret);
}

