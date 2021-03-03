#include "../incs/minishell.h"

char			*get_eval(
				t_list *list_head,
				char *tar)
{
	char	*ret;
	t_list	*cur;
	t_env	*tmp_env;

	cur = list_head;
	while (cur)
	{
		tmp_env = (t_env *)(cur->data);
		if (!(ft_strncmp(tmp_env->key, tar, ft_strlen(tar))))
			return (tmp_env->val);
		cur = cur->next; 
	}
	return (ret);
}
