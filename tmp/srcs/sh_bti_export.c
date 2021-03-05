#include "../incs/minishell.h"

static int	sh_bti_export_err_case(t_env *env)
{
	int	ret;

	ret = 0;

	return (ret);
}

int	sh_bti_export(char **args, t_list *env_list)
{
	t_list	*tmp_elist;
	t_env	*tmp_env;

	if (!(tmp_env = get_env(args[0])))
		return (1);
	if (del_quote(&(tmp_env->key)))
		return (1);
	if (del_quote(&(tmp_env->val)))
		return (1);
	printf("new env => key: %s, val: %s\n", tmp_env->key, tmp_env->val);
	// deal with double equal case (ex)
	tmp_elist = get_elist(env_list, tmp_env->key);
	if (tmp_elist)
		mod_eval((t_env *)(tmp_elist->data), tmp_env->val); 
	else
		add_elist(&env_list, tmp_env->key, tmp_env->val);
	return (0);
}
