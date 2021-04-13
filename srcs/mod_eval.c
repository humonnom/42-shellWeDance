#include "../incs/minishell.h"

int	mod_eval(t_env *env, char *new_val)
{
	free(env->val);
	env->val = NULL;
	if (!(env->val = ft_strdup(new_val)))
		return (1);
	return (0);
}
