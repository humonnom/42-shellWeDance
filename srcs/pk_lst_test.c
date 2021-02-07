#include "minishell.h"

int main()
{
	t_slist *set_list;
	t_slist *cur;

	pk_lstadd_front(&set_list, "test1");
	pk_lstadd_front(&set_list, "test2");
	pk_lstadd_front(&set_list, "test3");
	cur = set_list;
	while (cur)
	{
		ps(cur->data->data);
		cur = cur->next;
	}
	free(set_list);
}
