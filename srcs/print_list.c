/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:02 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:20:03 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_list(t_list *head)
{
	t_list *now;

	now = head;
	while (now)
	{
		printf("%s\n", (char *)now->data);
		now = now->next;
	}
}
