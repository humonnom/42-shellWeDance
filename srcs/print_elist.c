/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:19:14 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:19:17 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_elist(t_list *head)
{
	t_list	*cur;
	t_env	*tmp_env;

	cur = head;
	while (cur)
	{
		tmp_env = (t_env *)(cur->data);
		printf("%s=%s\n", tmp_env->key, tmp_env->val);
		cur = cur->next;
	}
}
