#include "../incs/minishell.h"

int			mod_elist(
			t_list **list_head,
			char *key, char *val)
{
	int		index;
	int		ret;
	t_list	*tar;
	t_env	*tmp_env;

	ret = 0;
	if ((tar = get_elist(*list_head, key)))
	{
		tmp_env = (t_env *)tar->data;
		free(tmp_env->val);
		if (!(tmp_env->val = ft_strdup(val)))
			ret = 1;
	}
	return (ret);
}

