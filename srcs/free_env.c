#include "../incs/minishell.h"

void	free_env(t_env *env)
{
	if (env->key)
		free(env->key);
	if (env->val)
		free(env->val);
	if (env)
		free(env);
}
