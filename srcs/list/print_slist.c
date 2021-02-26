#include "../incs/minishell.h"

void print_slist(t_list *set_list) {
	t_list *cur;
	int		idx;

	idx = 0;
	cur = set_list;
	while (cur) {
		printf("index: %d\n", idx++);
		printf("%s\n", (char *)(cur->data));
		cur = cur->next;
	}
}
