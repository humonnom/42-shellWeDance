/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:15:18 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 11:12:38 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static int
	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

static int
	get_cmd_size(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (!is_quote(*str))
			++ret;
		++str;
	}
	return (ret);
}

static char
	*copy_without_quote(char *str)
{
	char	*ret;
	int		ret_size;
	int		str_idx;
	int		ret_idx;

	ret_size = get_cmd_size(str);
	if (!(ret = (char *)malloc(sizeof(char) * (ret_size + 1))))
		return (NULL);
	ret[ret_size] = '\0';
	str_idx = -1;
	ret_idx = -1;
	while (str[++str_idx])
	{
		if (!is_quote(str[str_idx]))
			ret[++ret_idx] = str[str_idx];
	}
	return (ret);
}

int
	del_quote(char **str)
{
	char	*ret;

	if (!(ret = copy_without_quote(*str)))
		return (1);
	free(*str);
	*str = ret;
	return (0);
}
