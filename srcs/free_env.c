#include "../incs/minishell.h"

void	free_env(void *_env)
{
	t_env *env;

	env = (t_env *)_env;
	free(env->key);
	env->key = NULL;
	free(env->val);
	env->val = NULL;
	free(env);
	env = NULL;
}
