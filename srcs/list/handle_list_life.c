#include "../minishell.h"

int					convert_str2list(
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
	while (ret == 0 && str[--len])
	{
		if ((tmp_set = ft_strdup(str[len])) == NULL)
			ret = 1;
		ft_lstadd_front(list_head, ft_lstnew(tmp_set));
	}
	return (ret);

}

void				free_list(
					t_list **list_head)
{
	t_list *cur;
	t_list *tmp;

	cur = *list_head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		ft_lstdelone(tmp, &free);
	}
	*list_head = NULL;
}
