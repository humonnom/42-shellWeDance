/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:28 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 11:17:09 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	show_error(char const *str)
{
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	return (EXIT_FAILURE);
}
