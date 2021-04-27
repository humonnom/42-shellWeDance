/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:24 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 13:45:22 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

static int
	cmp_key(t_list *env_list, char *tmp_key)
{
	char	*key;

	key = ((t_env *)(env_list->data))->key;
	return (exact_strncmp(key, tmp_key));
}

static void
	del_elist_if(
	t_list **env_list,
	char *arg)
{
	t_list	*tmp;
	t_list	*cur;

	cur = *env_list;
	while (cur)
	{
		if (!cmp_key(cur, arg))
		{
			tmp = cur;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			ft_lstdelone(tmp, &free_env);
		}
		cur = cur->next;
	}
}

//TODO: end of tmp_key is '='
//      head of env.value is '=' => env.vlaue = env.value + 1
//	    find reason why we don't get changed value after handl_arg..

#if 0
	if (exact_strncmp(cmd_type, "unset") == 0)
		env->val = &(env->val[1]);

	if (exact_strncmp(cmd_type, "unset") == 0\
			&& env->key[ft_strlen(env->key) - 1] == '=')
	{
		g_signal = 1;
		if (flag_print)
			printf("%s: not an identifier: `%s'\n", cmd_type, env->val);
		return (ERR_INVALID_KEY);
	}

static int
	is_digit_in_arg_head(t_env *env, int flag_print)
{
	if (ft_isdigit((env->key)[0]))
	{
		g_signal = 1;
		if (flag_print)
			printf("%s: not an identifier: `%s'\n", cmd_type, env->key);
		return (ERR_EXPORT_NUM_KEY);
	}
	return (0);
}

static int
	check_unset_invalid_case(t_env *env, int flag_print)
{
	if (is_invalid_key(env, flag_print, "unset"))
		return (1);
	if (is_digit_in_arg_head(env, flag_print))
		return (1);
	return (0);
}
#endif

int
	sh_bti_unset(
	char **args,
	t_list **env_list,
	int flag_print)
{
	int		idx;
	int		ret;
	char	*tmp_arg;

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
		tmp_arg = args[idx];
		args[idx] = handle_arg(tmp_arg, *env_list);
		printf("arg[%d]: %s\n", idx, args[idx]);
#endif
		//ret |= check_unset_invalid_case(&env, flag_print);
		del_elist_if(env_list, args[idx]);
		free(tmp_arg);
	}
	g_signal = 0;
	return (0);
}
