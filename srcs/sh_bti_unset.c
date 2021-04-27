/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:24 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:15:44 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

#define ERR_UNSET_INVALID_ARG 4

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
	if (cur && !cmp_key(cur, arg))
	{
		tmp = cur;
		cur = cur->next;
		cur->next->prev = NULL;
		*env_list = cur;
		ft_lstdelone(tmp, &free_env);
	}
	while (cur)
	{
		if (!cmp_key(cur, arg))
		{
			tmp = cur;
			cur->prev->next = cur->next;
			if (cur->next)
				cur->next->prev = cur->prev;
			ft_lstdelone(tmp, &free_env);
		}
		cur = cur->next;
	}
}

static int
	is_valid_arg_for_unset(char *arg, int flag_print)
{
	if (ft_isdigit(arg[0])\
			|| arg[0] == '=' || arg[ft_strlen(arg) - 1] == '=')
	{
		g_signal = 1;
		if (flag_print)
			printf("unset: not an identifier: `%s'\n", arg);
		return (ERR_UNSET_INVALID_ARG);
	}
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
		tmp_arg = args[idx];
		args[idx] = handle_arg(tmp_arg, *env_list);
		ret |= !is_valid_arg_for_unset(args[idx], flag_print);
		del_elist_if(env_list, args[idx]);
		free(tmp_arg);
	}
	g_signal = 0;
	return (0);
}
