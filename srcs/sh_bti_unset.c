/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:24 by juepark           #+#    #+#             */
/*   Updated: 2021/04/26 22:55:39 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

static int
	cmp_key(t_list *env_list, char *key2)
{
	t_env	*tmp_env;
	char	*key;

	tmp_env = (t_env *)(env_list->data);
	key = tmp_env->key;
	return (exact_strncmp(key, key2));
}

static void
	del_elist_if(
	t_list **env_list,
	char *key)
{
	t_list	*prev;
	t_list	*next;
	t_list	*tmp;

	while (*env_list && !cmp_key(*env_list, key))
	{
		tmp = *env_list;
		*env_list = (*env_list)->next;
		free_elist(tmp);
	}
	prev = *env_list;
	while (prev && prev->next)
	{
		next = prev->next;
		if (!cmp_key(next, key))
		{
			tmp = next;
			prev->next = next->next;
			free_elist(tmp);
		}
		else
			prev = next;
	}
}

//TODO: end of tmp_key is '='
//      head of env.value is '=' => env.vlaue = env.value + 1
//	    find reason why we don't get changed value after handl_arg..

static int
	check_unset_invalid_case(t_env *env, int flag_print)
{
	if (is_invalid_key(env, flag_print, "unset"))
		return (1);
	if (is_digit_in_key_head(env, flag_print, "unset"))
		return (1);
	return (0);
}

int
	sh_bti_unset(
	char **args,
	t_list **env_list,
	int flag_print)
{
	int		idx;
	int		ret;
	char	*tmp_key;
	t_env	env;

	if (!args)
	{
		g_signal = 1;
		return (1);
	}
	idx = -1;
	ret = 0;
	while (args[++idx])
	{
#if 1
		tmp_key = args[idx];
		args[idx] = handle_arg(tmp_key, *env_list);
		env.key = args[idx];
		env.val = args[idx];
#endif
		ret |= check_unset_invalid_case(&env, flag_print);
		del_elist_if(env_list, env.key);
		free(tmp_key);
	}
	g_signal = 0;
	return (0);
}
