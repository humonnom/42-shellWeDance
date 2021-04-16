/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:18:39 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:18:39 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	is_key_arrow(long c)
{
	if (c == KEY_LEFT_ARROW)
		return (1);
	if (c == KEY_RIGHT_ARROW)
		return (1);
	if (c == KEY_UP_ARROW)
		return (1);
	if (c == KEY_DOWN_ARROW)
		return (1);
	return (0);
}
