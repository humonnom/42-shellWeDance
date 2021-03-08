#include "../../incs/minishell.h"

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
		if (ft_strlen(tmp_env->key) > ft_strlen(tar))
			cmp_len = ft_strlen(tmp_env->key);
		else
			cmp_len = ft_strlen(tar);
		if (!(ft_strncmp(tmp_env->key, tar, cmp_len)))
			return (cur);
		cur = cur->next; 
	}
	return (NULL);
}
