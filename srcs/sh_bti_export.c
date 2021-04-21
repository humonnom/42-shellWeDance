/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:54:01 by yekim             #+#    #+#             */
/*   Updated: 2021/04/21 20:52:38 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

#define ERR_EXPORT_EQUAL 1
#define ERR_EXPORT_EMPTY_KEY 4
#define CASE_EXPORT_EMPTY_VAL 2
#define CASE_EXPORT_NUMBER_KEY 3

extern int g_signal;

#if 1
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
		return (2);
	if (!(env->val = ft_strjoin(&(env->key[idx + 1]), env->val)))
		return (1);
	tmp_key = env->key;
	env->key = ft_substr(tmp_key, 0, idx);
	free(tmp_key);
	return (0);
}
#endif

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

static int	run_export(t_list *env_list, char *arg, int flag_print)
{
	t_list	*tmp_elist;
	int		err_case;
	t_env	*tmp_env;
	char	*tmp_val;
	int		ret;
	int		equal_in_key_flag;

	ret = 0;
	// should edit gen_env 
	equal_in_key_flag = 0;
	if (ft_strchr(arg, '='))
		equal_in_key_flag = 1;
	if (!(tmp_env = gen_env(arg)))
		return (1);
//	if (tmp_env->key[0] != '\0' && tmp_env->val[0] == '\0' && !equal_in_key_flag)
//		return (0);
	// key is not null, value is null, equal_in_key_flat => abc=
	tmp_env->key = handle_arg(tmp_env->key, env_list);
	tmp_env->val = handle_arg(tmp_env->val, env_list);
	if (ft_strchr(tmp_env->key, '='))
		equal_in_key_flag = 1;
	printf("tmp_env->key: %s\n", tmp_env->key);
	printf("tmp_env->val: %s\n", tmp_env->val);
	if (tmp_env->key[0] == '\0' && !equal_in_key_flag && tmp_env->val[0] == '\0')
	{
		if (flag_print)
		{
			tmp_elist = sort_elist(env_list);
			print_elist(tmp_elist);
		}
		return (0);	
	}
	if (is_invalid_key(tmp_env->key) || is_invalid_val(tmp_env->val))
		return (1);
	if (tmp_env->key[0] != '\0' && !equal_in_key_flag && tmp_env->val[0] == '\0')
	{
		return (0);	
	}
	if (tmp_env->key[0] != '\0' && tmp_env->val[0] == '\0' && equal_in_key_flag)
		ret = copy_str_key_to_val(tmp_env);
	tmp_elist = get_elist(env_list, tmp_env->key);
	if (tmp_elist)
		mod_eval((t_env *)(tmp_elist->data), tmp_env->val);
	else
		add_elist(&env_list, tmp_env->key, tmp_env->val);
#if 0
	if (ret == 2)
		return (0);
//	printf("tmp_env->key: %s\n", tmp_env->key);
//	printf("tmp_env->val: %s\n", tmp_env->val);

#endif
#if 0
	if (del_quote(&(tmp_env->key)))
		return (1);
#endif
	//err_case = sh_bti_export_err_case(tmp_env, equal_in_key_flag);
//	tmp_val = tmp_env->val;
//	tmp_env->val = handle_arg(tmp_env->val, env_list);
#if 0
	free(tmp_val);
	if (copy_str_key_to_val(tmp_env))
		return (1);
	if (err_case)
		return (handle_err_case(err_case, tmp_env));
#endif
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
//	int		equal_in_key_flag;

	if (!args)
		return (1);
	idx = -1;
	while (args[++idx])
	{
//		equal_in_key_flag = 0;
//		if (ft_strchr(args[idx], '='))
//			equal_in_key_flag = 1;
		if (run_export(*env_list, args[idx], flag_print))
			return (1);
	}
	if (idx == 0 && flag_print)
	{
		tmp_elist = sort_elist(*env_list);
		print_elist(tmp_elist);
	}
	return (0);
}
