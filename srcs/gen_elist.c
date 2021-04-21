/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_elist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:16:19 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 13:13:14 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_list
	*gen_elist(char **str)
{
	int		error_num;
	int		idx;
	t_env	*tmp_env;
	t_list	*ret;

	ret = NULL;
	error_num = 0;
	idx = -1;
	while (error_num == 0 && str[++idx])
	{
		if (!(tmp_env = gen_env(str[idx])))
			error_num = 1;
		ft_lstadd_back(&ret, ft_lstnew(tmp_env));
	}
	return (ret);
}
