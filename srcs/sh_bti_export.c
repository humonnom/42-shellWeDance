#include "../incs/minishell.h"

static int	sh_bti_export_err_case(t_env *env)
{
	if (env->val[0] == '=')
	{
		return (1);
	}

	return (0);
}

int	sh_bti_export(char **args, t_list *env_list)
{
	t_list	*tmp_elist;
	t_env	*tmp_env;
	int		err_case;

	if (!(tmp_env = get_env(args[0])))
		return (1);
	err_case = sh_bti_export_err_case(tmp_env);
	if (del_quote(&(tmp_env->key)))
		return (1);
	if (del_quote(&(tmp_env->val)))
		return (1);
	if (err_case)
	{
		printf("zsh: %s not found\n", &(tmp_env->val[1]));
		return (1);
	}
	printf("new env => key: %s, val: %s\n", tmp_env->key, tmp_env->val);
	// deal with double equal case (ex)
	tmp_elist = get_elist(env_list, tmp_env->key);
	if (tmp_elist)
		mod_eval((t_env *)(tmp_elist->data), tmp_env->val); 
	else
		add_elist(&env_list, tmp_env->key, tmp_env->val);
	return (0);
}
