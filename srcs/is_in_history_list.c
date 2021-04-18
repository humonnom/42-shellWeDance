/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_history_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:24 by juepark           #+#    #+#             */
/*   Updated: 2021/04/18 22:43:33 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	is_in_history_list(
	t_list *history_ptr,
	char *target)
{
	t_list	*curr;

	curr = history_ptr;
	while (curr)
	{
		if (curr->data) 
			printf("%s\n", curr->data);
		curr = curr->next;
	}
	return (0);
}
