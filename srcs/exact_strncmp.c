/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exact_strncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:15:22 by juepark           #+#    #+#             */
/*   Updated: 2021/04/23 14:10:05 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	exact_strncmp(char *str1, char *str2)
{
	int	len;

	len = get_max_strlen(str1, str2);
	return (ft_strncmp(str1, str2, len));
}
