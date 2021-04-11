#include "../incs/minishell.h"

char			*get_eval(
				t_list *list_head,
				char *tar)
{
	char	*ret;
	t_list	*tmp_list;
	t_env	*tmp_env;

	if (!(tmp_list = get_elist(list_head, tar)))
		return (NULL);
	if (!(tmp_env = (t_env *)(tmp_list->data)))	
		return (NULL);
	return (tmp_env->val);
}