#include "../incs/minishell.h"

#define ERR_EXPORT_EQUAL 1
#define ERR_EXPORT_EMPTY_KEY 4
#define CASE_EXPORT_EMPTY_VAL 2
#define CASE_EXPORT_NUMBER_KEY 3

static int	copy_str_key_to_val(t_env *env)
{
	int		idx;
	char	*new_val;

	idx = -1;
	while (env->key[++idx])
	{
		if (env->key[idx] == '=')
			break ;
	}
	if (idx == ft_strlen(env->key))
		return (0);
	if (!(env->val = ft_strjoin(&(env->key[idx]), env->val)))
		return (1);
	//free(&(env->key[idx]));
	env->key[idx] = '\0';
	return (0);
}

static int	sh_bti_export_err_case(t_env *env, int eqaul_in_key)
{
	if ((env->key)[0] == '\0')
		return (ERR_EXPORT_EMPTY_KEY);
	if (ft_isdigit((env->key)[0]))
		return (CASE_EXPORT_NUMBER_KEY);
	if (env->val[0] == '=')
		return (ERR_EXPORT_EQUAL);
	if (!eqaul_in_key && (env->val == NULL || env->val[0] == '\0'))
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
	if (err_case == ERR_EXPORT_EMPTY_KEY)
	{
		printf("export: not an identifier: %s\n", env->val);
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
	int		equal_in_key;

	equal_in_key = 0;
	if (ft_strchr(arg, '='))
		equal_in_key = 1;
	if (!(tmp_env = get_env(arg)))
		return (1);
	printf("tmp_env->key: %s, tmp_env->val: %s\n", tmp_env->key, tmp_env->val);
	if (del_quote(&(tmp_env->key)))
		return (1);
	err_case = sh_bti_export_err_case(tmp_env, equal_in_key);
	if (del_quote(&(tmp_env->val)))
		return (1);
	// if key has equal sign, mv after = to value
	if (copy_str_key_to_val(tmp_env))
		return (1);
	printf("tmp_env->key: %s, tmp_env->val: %s\n", tmp_env->key, tmp_env->val);
	if (err_case)
		return (handle_err_case(err_case, tmp_env));
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
