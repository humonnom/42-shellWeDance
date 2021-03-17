#include "../incs/minishell.h"

void	del_env(void *tar)
{
	t_env *tmp;

	tmp = (t_env *)tar;
	free(tmp->key);
	free(tmp->val);
	free(tar);
}
