/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:24 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:44:41 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char			*get_eval(
				t_list *list_head,
				char *tar)
{
	t_list	*tmp_list;
	t_env	*tmp_env;

	if (!(tmp_list = get_elist(list_head, tar)))
		return (NULL);
	if (!(tmp_env = (t_env *)(tmp_list->data)))
		return (NULL);
	return (tmp_env->val);
}
