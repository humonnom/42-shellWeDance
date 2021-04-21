/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_darr_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:38 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 11:23:39 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	set_darr_to_list(
	t_list **list_head,
	char **str)
{
	int		ret;
	int		len;
	char	*tmp_tokens;

	ret = 0;
	len = 0;
	while (ret == 0 && str[len])
		len++;
	while (ret == 0 && --len >= 0)
	{
		tmp_tokens = ft_strdup(str[len]);
		if (tmp_tokens == NULL)
			ret = 1;
		ft_lstadd_front(list_head, ft_lstnew(tmp_tokens));
	}
	return (ret);
}
