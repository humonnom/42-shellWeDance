/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:30 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 11:26:10 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	calc_min(int num1, int num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

int
	calc_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
