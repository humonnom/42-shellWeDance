#include "minishell.h"

void	pk_lstadd_front(
		t_slist **set_head,
		void	*content)
{
	t_alist	*a_new;
	t_slist *s_new;

	if (!set_head && !content)
		return ;
	if (!(a_new = (t_alist *)malloc(sizeof(t_alist))))
		return ;
	a_new->data = content;
	a_new->next = NULL;
	if (!(s_new = (t_slist *)malloc(sizeof(t_slist))))
		return ;
	s_new->data = a_new;
	s_new->next = NULL;
	if (*set_head)
		s_new->next = *set_head;
	*set_head = s_new;	
}
