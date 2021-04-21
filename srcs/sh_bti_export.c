/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:54:01 by yekim             #+#    #+#             */
/*   Updated: 2021/04/21 21:49:26 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

#define ERR_EXPORT_EQUAL 1
#define CASE_EXPORT_START_WITH_EQUAL 5
#define ERR_EXPORT_EMPTY_KEY 4
#define CASE_EXPORT_EMPTY_VAL 2
#define CASE_EXPORT_NUMBER_KEY 3

extern int g_signal;

static int
	copy_str_key_to_val(t_env *env)
{
	int		idx;
	char	*tmp_key;
	char	*new_val;

	idx = 0;
	while (env->key[idx])
	{
		if (env->key[idx] == '=')
			break ;
		++idx;
	}
	//not found '='
	if (idx == ft_strlen(env->key))
		return (0);
	if (!(env->val = ft_strjoin(&(env->key[idx + 1]), env->val)))
		return (1);
	tmp_key = env->key;
	env->key = ft_substr(tmp_key, 0, idx);
	free(tmp_key);
	return (0);
}

#if 0
static int	sh_bti_export_err_case(t_env *env, int equal_in_key_flag)
{
	if ((env->key)[0] == '\0')
		return (ERR_EXPORT_EMPTY_KEY);
	if (ft_isdigit((env->key)[0]))
		return (CASE_EXPORT_NUMBER_KEY);
	if (env->val[0] == '=')
		return (ERR_EXPORT_EQUAL);
	if (!equal_in_key_flag && (env->val == NULL || env->val[0] == '\0'))
		return (CASE_EXPORT_EMPTY_VAL);
	return (0);
}
#endif

static int	handle_err_case(int err_case, t_env *env)
{
	if (err_case == CASE_EXPORT_NUMBER_KEY)
	{
		printf("export: not an identifier: %s\n", env->key);
		g_signal = 1;
		return (1);
	}
	if (err_case == ERR_EXPORT_EQUAL)
	{
		printf("%s not found\n", &(env->val[1]));
		g_signal = 1;
		return (1);
	}
	if (err_case == CASE_EXPORT_EMPTY_VAL)
	{
		free_env(env);
		return (0);
	}
	return (0);
}

static int
	is_invalid_key(char *env_key)
{
	if (env_key[0] == '\0')
		return (ERR_EXPORT_EMPTY_KEY);
	if (env_key[0] == '=')
		return (ERR_EXPORT_EMPTY_KEY);
	if (ft_isdigit((env_key)[0]))
		return (CASE_EXPORT_NUMBER_KEY);
	return (0);
}

static int
	is_invalid_val(char *env_val)
{
#if 0
	if (!equal_in_key_flag && (env->val == NULL || env->val[0] == '\0'))
		return (CASE_EXPORT_EMPTY_VAL);
#endif
	return (0);
}

static int
	is_equal_in_str(char *str)
{
	int	ret;

	ret = 0;
	if (ft_strchr(str, '='))
		ret = 1;
	return (ret);
}

static int
	is_empty_str(char *str)
{
	if (!str)
		return (0); 
	if (str[0] == '\0')
		return (1);
	return (0);
}

static int
	run_export_part(
	t_env *env,
	t_list *env_list,
	int flag_equal,
	int flag_print)
{
	if (!is_empty_str(env->key) && is_empty_str(env->val) && !flag_equal)
	{
		if (flag_print)
			print_sorted_elist(env_list);
		return (0);
	}
	if (is_invalid_key(env->key) || is_invalid_val(env->val))
		return (1);
	if (!is_empty_str(env->key) && is_empty_str(env->val) && !flag_equal)
		return (0);
	return (2);
}

static int
	run_export(
	t_list *env_list,
	char *arg,
	int flag_equal,
	int flag_print)
{
	t_list	*tmp_elist;
	t_env	*tmp_env;
	int		ret;

	if (!(tmp_env = gen_env(arg)))
		return (1);
	tmp_env->key = handle_arg(tmp_env->key, env_list);
	tmp_env->val = handle_arg(tmp_env->val, env_list);
	flag_equal = is_equal_in_str(tmp_env->key);
	ret = run_export_part(tmp_env, env_list, flag_equal, flag_print);
	if (ret == 1 || ret == 0)
		return (ret);
	ret = 0;
	if (!is_empty_str(tmp_env->key) && is_empty_str(tmp_env->val) && flag_equal)
		ret = copy_str_key_to_val(tmp_env);
	tmp_elist = get_elist(env_list, tmp_env->key);
	if (tmp_elist)
		mod_eval((t_env *)(tmp_elist->data), tmp_env->val);
	else
		add_elist(&env_list, tmp_env->key, tmp_env->val);
	return (ret);
}

int
	sh_bti_export(
	char **args,
	t_list **env_list,
	int flag_print)
{
	t_list	*tmp_elist;
	int		idx;
	int		flag_equal_in_key;

	if (!args)
		return (1);
	idx = -1;
	while (args[++idx])
	{
		flag_equal_in_key = is_equal_in_str(args[idx]);
		if (run_export(*env_list, args[idx],flag_equal_in_key,  flag_print))
			return (1);
	}
	if (idx == 0 && flag_print)
		print_sorted_elist(*env_list);
	return (0);
}
