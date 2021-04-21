/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:24:52 by yekim             #+#    #+#             */
/*   Updated: 2021/04/21 11:25:09 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static char
	*cvt_env_to_str(t_env *env)
{
	char	*ret;
	char	*tmp;

	ret = ft_strjoin(env->key, "=");
	tmp = ft_strjoin(ret, env->val);
	free(ret);
	ret = tmp;
	return (ret);
}

static int
	swap_str(t_list *cur, t_list *next)
{
	t_env		*tmp_env;
	char		*cur_str;
	char		*next_str;

	cur_str = cvt_env_to_str(cur->data);
	next_str = cvt_env_to_str(next->data);
	if (exact_strncmp(cur_str, next_str) > 0)
	{
		tmp_env = cur->data;
		cur->data = (void *)next->data;
		next->data = (void *)tmp_env;
		return (1);
	}
	free(cur_str);
	free(next_str);
	return (0);
}

t_list
	*sort_elist(t_list *cur)
{
	t_list		*beg;

	beg = cur;
	while (cur->next != NULL)
	{
		if (swap_str(cur, cur->next))
			cur = beg;
		else
			cur = cur->next;
	}
	return (beg);
}
