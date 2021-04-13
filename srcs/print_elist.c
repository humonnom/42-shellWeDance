#include "../incs/minishell.h"

void	print_elist(t_list *head)
{
	t_list	*cur;
	t_env	*tmp_env;

	cur = head;
	while (cur)
	{
		tmp_env = (t_env *)(cur->data);
		printf("%s=%s\n", tmp_env->key, tmp_env->val);
		cur = cur->next;
	}
}
