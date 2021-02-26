#include "../incs/minishell.h"

void print_slist(t_list *set_list) {
	t_list *cur;

	cur = set_list;
	while (cur) {
		printf("%s\n", (char *)(cur->data));
		cur = cur->next;
	}
}
