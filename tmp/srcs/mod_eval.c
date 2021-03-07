#include "../incs/minishell.h"

int	mod_eval(t_env *env, char *new_val)
{
	if (env->val)
	{
		free(env->val);
		env->val = NULL;
	}
	if (!(env->val = ft_strdup(new_val)))
		return (1);
	if (new_val)
	{
		free(new_val);
		env->val = NULL;
	}
	return (0);
}
