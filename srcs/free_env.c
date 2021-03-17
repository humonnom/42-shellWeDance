#include "../incs/minishell.h"

void	free_env(void *tar)
{
	t_env *env;

	env = (t_env *)tar;
	free(env->key);
	env->key = NULL;
	free(env->val);
	env->val = NULL;
	free(env);
	env = NULL;
}
