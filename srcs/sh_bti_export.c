#include "../incs/minishell.h"

#define ERR_EXPORT_EQUAL 1
#define CASE_EXPORT_EMPTY_VAL 2
#define CASE_EXPORT_NUMBER_KEY 3

static int	is_beg_nbr(char *str)
{
	if (str == NULL)
		return (0);
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}

static int	sh_bti_export_err_case(t_env *env)
{
	if (is_beg_nbr(env->key))
		return (CASE_EXPORT_NUMBER_KEY);
	if (env->val[0] == '=')
		return (ERR_EXPORT_EQUAL);
	if (env->val == NULL || env->val[0] == '\0')
		return (CASE_EXPORT_EMPTY_VAL);
	return (0);
}

static int	handle_err_case(int err_case, t_env *env)
{
	if (err_case == CASE_EXPORT_NUMBER_KEY)
	{
		printf("export: not an identifier: %s\n", env->key);
		return (1);	
	}
	if (err_case == ERR_EXPORT_EQUAL)
	{
		printf("zsh: %s not found\n", &(env->val[1]));
		return (1);
	}
	if (err_case == CASE_EXPORT_EMPTY_VAL)
	{
		free_env(env);
		return (0);
	}
	return (0);
}

static int	run_export(t_list *env_list, char *arg)
{
	t_list	*tmp_elist;
	int		ret;
	int		err_case;
	t_env	*tmp_env;

	if (!(tmp_env = get_env(arg)))
		return (1);
	if (del_quote(&(tmp_env->key)))
		return (1);
	err_case = sh_bti_export_err_case(tmp_env);
	if (del_quote(&(tmp_env->val)))
		return (1);
	if (err_case)
		return (handle_err_case(err_case, tmp_env));
	// deal with double equal case (ex)
	tmp_elist = get_elist(env_list, tmp_env->key);
	if (tmp_elist)
		mod_eval((t_env *)(tmp_elist->data), tmp_env->val); 
	else
		add_elist(&env_list, tmp_env->key, tmp_env->val);
	return (ret);
}

int	sh_bti_export(char **args, t_info *info)
{
	int	idx;

	if (!args)
		return (1);
	idx = -1;
	while (args[++idx])
		run_export(info->env_list, args[idx]);
	return (0);
}
