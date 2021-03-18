#include "../incs/minishell.h"

void	print_list(t_list *head)
{
	t_list *now;

	now = head;
	while (now)
	{
		printf("%s\n", (char *)now->data);
		now = now->next;
	}
}
