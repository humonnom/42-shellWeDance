/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:19:56 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 13:19:54 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void
	print_line_list(t_list *head)
{
	t_list		*cur;
	t_tokens	*tmp_tokens;

	cur = head;
	while (cur)
	{
		tmp_tokens = (t_tokens *)(cur->data);
		print_tokens(tmp_tokens);
		cur = cur->next;
	}
}
