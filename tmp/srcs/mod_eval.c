#include "../incs/minishell.h"

int	mod_eval(t_env *env, char *new_val)
{
	free(env->val);
	if (!(env->val = ft_strdup(new_val)))
		return (1);
	if (new_val)
		free(new_val);
	return (0);
}
