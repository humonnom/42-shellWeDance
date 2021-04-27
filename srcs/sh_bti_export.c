/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:54:01 by yekim             #+#    #+#             */
/*   Updated: 2021/04/27 14:53:14 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

static int
	copy_str_key_to_val(t_env *env)
{
	int		idx;
	char	*tmp_key;

	idx = 0;
	while (env->key[idx])
	{
		if (env->key[idx] == '=')
			break ;
		++idx;
	}
	if (idx == (int)ft_strlen(env->key))
		return (0);
	if (!(env->val = ft_strjoin(&(env->key[idx + 1]), env->val)))
		return (1);
	tmp_key = env->key;
	env->key = ft_substr(tmp_key, 0, idx);
	free(tmp_key);
	return (0);
}

static int
	check_not_excuted_case(
	t_env *env,
	t_list *env_list,
	int flag_equal,
	int flag_print)
{
	if (is_digit_in_key_head(env, flag_print))
		return (1);
	if (is_empty_str(env->key) && is_empty_str(env->val) && !flag_equal)
	{
		if (flag_print)
			print_sorted_elist(env_list);
		return (0);
	}
	if (is_invalid_key(env, flag_print))
		return (1);
	if (!is_empty_str(env->key) && is_empty_str(env->val) && !flag_equal)
		return (0);
	return (2);
}

static int
	do_excuted_case(
	t_env *tmp_env,
	t_list *env_list,
	int flag_equal)
{
	t_list	*tmp_elist;
	int		ret;

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

static int
	run_export(
	t_list *env_list,
	char *arg,
	int flag_equal,
	int flag_print)
{
	t_env	*tmp_env;
	char	*tmp_key;
	char	*tmp_val;
	int		ret;

	if (!(tmp_env = gen_env(arg)))
		return (1);
	tmp_key = tmp_env->key;
	tmp_val = tmp_env->val;
	tmp_env->key = handle_arg(tmp_key, env_list);
	tmp_env->val = handle_arg(tmp_val, env_list);
	flag_equal |= is_equal_in_str(tmp_env->key);
	ret = check_not_excuted_case(tmp_env, env_list, flag_equal, flag_print);
	if (ret == 2)
		ret = do_excuted_case(tmp_env, env_list, flag_equal);
	free_env(tmp_env);
	free(tmp_key);
	free(tmp_val);
	return (ret);
}

int
	sh_bti_export(
	char **args,
	t_list **env_list,
	int flag_print)
{
	int		idx;
	int		ret;
	int		flag_equal_in_key;

	if (!args)
	{
		g_signal = 1;
		return (1);
	}
	ret = 0;
	idx = -1;
	while (args[++idx])
	{
		flag_equal_in_key = is_equal_in_str(args[idx]);
		if (run_export(*env_list, args[idx], flag_equal_in_key, flag_print))
			ret |= 1;
	}
	if (idx == 0 && flag_print)
		print_sorted_elist(*env_list);
	g_signal = ret;
	return (ret);
}
