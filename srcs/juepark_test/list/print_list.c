#include "../minishell.h"

void	print_list(t_list **head)
{
	t_list *now;

	now = *head;
	while (now)
	{
		ps(now->data);
		now = now->next;
	}
}
