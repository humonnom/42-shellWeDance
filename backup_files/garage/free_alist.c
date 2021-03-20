#include "../../incs/minishell.h"

void	free_alist(t_list **list_head)
{
	t_list	*cur;
	t_list	*tmp;

	cur = *list_head;
	while (cur)
	{
		tmp = cur;
		tmp_env =(t_env *)(tmp->data);
		cur = cur->next;
		free(tmp_env->key);
		free(tmp_env->val);
		ft_lstdelone(tmp, &free);
	}
	*list_head = NULL;
}
