/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:17 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 11:11:30 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int			add_elist(
			t_list **list_head,
			char *key, char *val)
{
	t_list	*tmp;
	t_env	*tmp_env;

	if (list_head == 0)
		return (1);
	if (!(tmp_env = (t_env *)malloc(sizeof(t_env))))
		return (1);
	if (!(tmp_env->key = ft_strdup(key)))
		return (1);
	if (!(tmp_env->val = ft_strdup(val)))
		return (1);
	tmp = ft_lstnew(tmp_env);
	ft_lstadd_back(list_head, tmp);
	return (0);
}
