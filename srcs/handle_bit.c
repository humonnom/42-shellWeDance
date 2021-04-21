/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:38 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 13:37:07 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	turn_on_bit(int val, int n)
{
	return (val |= (1 << n));
}

int	turn_off_bit(int val, int n)
{
	return (val &= ~(1 << n));
}

int	check_bit(int val, int n)
{
	if ((val >> n) & ON)
		return (ON);
	return (OFF);
}
