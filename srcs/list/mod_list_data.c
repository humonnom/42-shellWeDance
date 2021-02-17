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

int			modify_list_data(
			t_list **list_head,
			char *key, char *value)
{
	int index;
	int	ret;
	t_list *cur;

	ret = 0;
	if ((index = get_list_index(*list_head, key)) == -1)
		ret = 1;
	if (ret == 0)
	{	
		cur = *list_head;
		while (index--)
			cur = cur->next;
		free(cur->data);
		cur->data = get_new_data(key, value);
	}
	if (!(cur->data))
		ret = 1;
	return (ret);
}

