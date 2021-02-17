#include "../../incs/minishell.h"

char*		get_list_data(
			t_list *list_head,
			char *target)
{
	t_list	*cur;

	cur = list_head;
	while (cur)
	{
		if (!!(ft_strnstr(cur->data, target, ft_strlen(target))))
			return (cur->data);
		cur = cur->next; 
	}
	return (NULL);
}

