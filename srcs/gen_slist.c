#include "../incs/minishell.h"

//static int	set_type(char **str, )

//t_list	*gen_slist(char **str)
t_list	*gen_slist(t_info *info, char **str)
{
	int		error_num;
	int		idx;
	t_set	*tmp_set;
	t_list	*ret;

	ret = NULL;
	error_num = 0;
	idx = -1;
	while (error_num == 0 && str[++idx])
	{
		if (!(tmp_set = get_set(info, str[idx])))
			error_num = 1;
		if (str[idx + 1] == 0)
			tmp_set->type = TYPE_BREAK;
		else
			tmp_set->type = TYPE_PIPE;
		ft_lstadd_back(&ret, ft_lstnew(tmp_set));
	}
	return (ret);
}

