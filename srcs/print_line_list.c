#include "../incs/minishell.h"

void print_line_list(t_list *head) {
	t_list		*cur;
	t_tokens	*tmp_tokens;

	cur = head;
	while (cur)
	{
		tmp_tokens = (t_tokens *)(cur->data);
		print_tokens(tmp_tokens);
		cur = cur->next;
	}
}
