#include "../incs/minishell.h"

void	free_elist(t_list *list_head)
{
	t_list	*tmp;

	tmp = list_head;
	list_head->data = NULL;
	ft_lstdelone(tmp, &free_env);
}
