/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:17 by juepark           #+#    #+#             */
/*   Updated: 2021/04/22 11:42:55 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_list
	*get_elist(
	t_list *list_head,
	char *tar)
{
	t_list	*cur;
	t_env	*tmp_env;
	int		cmp_len;

	cur = list_head;
	while (cur)
	{
		tmp_env = (t_env *)(cur->data);
		cmp_len = get_max_strlen(tmp_env->key, tar);
		if (!(ft_strncmp(tmp_env->key, tar, cmp_len)))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}
