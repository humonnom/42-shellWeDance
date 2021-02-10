#include "minishell.h"

void				pk_lstadd_front(
					t_slist **set_head,
					t_slist	*new_list)
{
	if (*set_head)
		new_list->next = *set_head;
	*set_head = new_list;	
}

t_slist				*pk_lstnew(
					void *data)
{
	t_list	*new_list;
	t_slist *s_new_list;

	if (!data)
		return (0);
	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new_list->data = data;
	new_list->next = NULL;
	if (!(s_new_list = (t_slist *)malloc(sizeof(t_slist))))
		return (0);
	s_new_list->data = new_list;
	s_new_list->next = NULL;
	return (s_new_list);
}

void				pk_lstdelone(
					t_slist *target,
					void (*del)(void *))
{

	if (!target || !del)
		return ;
	del(target->data->data);
	free(target->data);
	free(target);
}
