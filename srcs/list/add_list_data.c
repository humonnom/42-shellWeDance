#include "../../incs/minishell.h"

static char	*get_new_data(
			char *key,
			char *value)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	ret = ft_strjoin(tmp, value);
	free(tmp);
	return (ret);
}

int			add_list_data(
			t_list **list_head,
			char *key, char *value)
{
	t_list	*tmp;

	if(list_head == 0)
		return (1);
	tmp = ft_lstnew(get_new_data(key, value));
	ft_lstadd_back(list_head, tmp);
	return (0);
}
