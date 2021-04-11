#include "../incs/minishell.h"

int	set_darr_to_list(
	t_list **list_head,
	char **str)
{
	int		ret;
	int		len;
	char	*tmp_set;

	ret = 0;	
	len = 0;
	while (ret == 0 && str[len])
		len++;
	while (ret == 0 && --len >= 0)
	{
		if ((tmp_set = ft_strdup(str[len])) == NULL)
			ret = 1;
		ft_lstadd_front(list_head, ft_lstnew(tmp_set));
	}
	return (ret);

}

