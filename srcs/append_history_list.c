/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_history_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:24 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 11:18:32 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void
	append_history_list(t_list **history, char *line)
{
	t_list	*new_list;
	t_list	*head;
	t_list	*head_next;

	new_list = ft_lstnew(line);
	head = *history;
	head_next = head->next;
	new_list->next = head_next;
	new_list->prev = head;
	head->next = new_list;
	head_next->prev = new_list;
	*history = head;
}
