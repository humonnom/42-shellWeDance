/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_darr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:19:10 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:19:11 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_darr(char **str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		printf("str[%d]: %s\n", idx, str[idx]);
}
