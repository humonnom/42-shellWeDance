/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bracket_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:34 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:50:09 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static int
	is_bracket_error(
	char *str,
	int *idx,
	char bracket,
	int *cnt)
{
	while (str[*idx] && str[*idx] == bracket && (*cnt)--)
		++(*idx);
	if (str[*idx] == bracket)
		return (TYPE_ERROR);
	return (0);
}

int
	set_bracket_type(char *str, int *idx)
{
	int		cnt;

	cnt = 2;
	if (is_bracket_error(str, idx, '>', &cnt))
		return (TYPE_ERROR);
	if (cnt == 1)
		return (TYPE_REOUT);
	if (cnt == 0)
		return (TYPE_REOUT_D);
	cnt = 1;
	if (is_bracket_error(str, idx, '<', &cnt))
		return (TYPE_ERROR);
	if (cnt == 0)
		return (TYPE_REIN);
	return (0);
}
