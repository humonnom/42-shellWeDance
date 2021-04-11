#include "../incs/minishell.h"

void	append_history_list(t_list **history, char *line)
{
	t_list	*new_list;
	t_list	*head;
	t_list	*head_next;

	new_list = ft_lstnew(line);
	head = *history;
	head_next = head->next;
	new_list->next = head_next;
	new_list->prev = head;

	head->next = new_list;
	head_next->prev = new_list;
	*history = head;
}
