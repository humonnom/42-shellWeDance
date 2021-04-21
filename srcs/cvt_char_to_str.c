/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_char_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:15:06 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 13:37:43 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*cvt_char_to_str(char c)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
