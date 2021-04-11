#include "../incs/minishell.h"

void print_slist(t_list *head) {
	t_list	*cur;
	t_set	*tmp_set;

	cur = head;
	while (cur)
	{
		tmp_set = (t_set *)(cur->data);
		print_set(tmp_set);
		cur = cur->next;
	}
}
