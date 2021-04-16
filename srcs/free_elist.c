/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:15:52 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:15:53 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	free_elist(t_list *list_head)
{
	t_list	*tmp;

	tmp = list_head;
	list_head->data = NULL;
	ft_lstdelone(tmp, &free_env);
}
