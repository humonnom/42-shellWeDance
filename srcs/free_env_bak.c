#include "../incs/minishell.h"

void	free_env(t_env *env)
{
	if (env->key)
	{
		free(env->key);
		env->key = NULL;
	}
	if (env->val)
	{
		free(env->val);
		env->val = NULL;
	}
	if (env)
	{
		free(env);
		env = NULL;
	}
}
