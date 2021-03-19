#include "../../incs/minishell.h"

void	print_alist(t_list *head)
{
	t_list	*cur;

	cur = head;
	while (cur)
	{
		printf("%s\n", (char *)cur->data);
		cur = cur->next;
	}
}
