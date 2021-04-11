#include "../incs/minishell.h"

t_list			*get_elist(
				t_list *list_head,
				char *tar)
{
	t_list	*cur;
	t_env	*tmp_env;
	int		cmp_len;

	cur = list_head;
	while (cur)
	{
		tmp_env = (t_env *)(cur->data);
		cmp_len = get_max_strlen(tmp_env->key, tar);
		if (!(ft_strncmp(tmp_env->key, tar, cmp_len)))
			return (cur);
		cur = cur->next; 
	}
	return (NULL);
}
