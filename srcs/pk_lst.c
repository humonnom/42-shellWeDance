#include "minishell.h"

void				pk_lstadd_front(
					t_slist **set_head,
					t_slist	*new)
{
	if (*set_head)
		new->next = *set_head;
	*set_head = new;	
}

t_slist				*pk_lstnew(
					void *data)
{
	t_list	*new;
	t_slist *s_new;

	if (!data)
		return (0);
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new->data = data;
	new->next = NULL;
	if (!(s_new = (t_slist *)malloc(sizeof(t_slist))))
		return (0);
	s_new->data = new;
	s_new->next = NULL;
	return (s_new);
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
