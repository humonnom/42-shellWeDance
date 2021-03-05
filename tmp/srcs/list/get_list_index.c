#include "../../incs/minishell.h"

int				get_list_index(
				t_list *list_head,
				char *target)
{
	t_list	*cur;
	int		i;

	i = -1;
	cur = list_head;
	while (cur)
	{
		++i;
		if (!!(ft_strnstr(cur->data, target, ft_strlen(target))))
			return (i);
		cur = cur->next; 
	}
	return (-1);
}
