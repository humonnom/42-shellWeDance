#include "../../incs/minishell.h"

void				free_list(t_list **list_head)
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
