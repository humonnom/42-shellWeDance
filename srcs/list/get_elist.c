#include "../../incs/minishell.h"

t_list			*get_elist(
				t_list *list_head,
				char *tar)
{
	t_list	*cur;
	t_env	*tmp_env;

	cur = list_head;
	while (cur)
	{
		tmp_env = (t_env *)cur->data;
		if (!(ft_strncmp(tmp_env->key, tar, ft_strlen(tar))))
			return (cur);
		cur = cur->next; 
	}
	return (NULL);
}
