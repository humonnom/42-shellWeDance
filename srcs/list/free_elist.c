#include "../../incs/minishell.h"

void	free_elist(t_list *list_head)
{
	t_list	*tmp;
	t_env	*tmp_env;

	tmp = list_head;
	tmp_env =(t_env *)(list_head->data);
	free_env(tmp_env);
	list_head->data = NULL;
	ft_lstdelone(tmp, &free);
}
