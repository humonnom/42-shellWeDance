#include "../minishell.h"

void	test_pk_lst()
{
	t_slist *set_list;
	t_slist *head;
	t_slist *tmp;


	ps("===TEST pk_lstnew ===\n");
	
	set_list = NULL;
	set_list = pk_lstnew(ft_strdup("test new1"));
	printf("	%s\n", set_list->data->data);
	printf("	%x\n", (unsigned int)set_list->next);
	pk_lstdelone(set_list, &free);

	set_list = NULL;
	set_list = pk_lstnew(ft_strdup("test new2"));
	printf("	%s\n", set_list->data->data);
	printf("	%x\n", (unsigned int)set_list->next);
	pk_lstdelone(set_list, &free);

	ps("===TEST pk_lstadd_front===\n");
	
	set_list = NULL;
	pk_lstadd_front(&set_list, pk_lstnew(ft_strdup("test1")));
	pk_lstadd_front(&set_list, pk_lstnew(ft_strdup("test2")));
	pk_lstadd_front(&set_list, pk_lstnew(ft_strdup("test3")));

	head = set_list;
	while (head)
	{
		printf("	data: %s\n", head->data->data);
		printf("	next: %x\n", (unsigned int)head->next);
		head = head->next;
	}

	ps("===TEST pk_delone===\n");
	head = set_list;
	while (head)
	{
		printf("	data: %s\n", head->data->data);
		printf("	next: %x\n", (unsigned int)head->next);
		tmp = head;
		head = head->next;
		pk_lstdelone(tmp, &free);
	}

	ps("======leaks check=====\n");
	while (1)
		;
}
