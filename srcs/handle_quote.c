/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:22:03 by yekim             #+#    #+#             */
/*   Updated: 2021/04/21 11:22:31 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static int	handle_squote_in_dquote(int val)
{
	int	ret;

	if (check_bit(val, BIT_DQUOTE))
		ret = turn_off_bit(val, BIT_SQUOTE);
	else
		ret = turn_on_bit(val, BIT_SQUOTE);
	return (ret);
}

static int	handle_dquote_in_squote(int val)
{
	int	ret;

	if (check_bit(val, BIT_SQUOTE))
		ret = turn_off_bit(val, BIT_DQUOTE);
	else
		ret = turn_on_bit(val, BIT_DQUOTE);
	return (ret);
}

int			handle_quote(
			char *str,
			char **str_cpy,
			char c)
{
	int	ret;
	int	str_cpy_idx;

	ret = 0;
	str_cpy_idx = -1;
	while (*str)
	{
		if (!check_bit(ret, BIT_SQUOTE) && *str == '\'')
			ret = handle_squote_in_dquote(ret);
		else if (!check_bit(ret, BIT_DQUOTE) && *str == '\"')
			ret = handle_dquote_in_squote(ret);
		else if (check_bit(ret, BIT_SQUOTE) && *str == '\'')
			ret = turn_off_bit(ret, BIT_SQUOTE);
		else if (check_bit(ret, BIT_DQUOTE) && *str == '\"')
			ret = turn_off_bit(ret, BIT_DQUOTE);
		if (*str == '\\' && *str != '\0')
		{
			++str;
			++str_cpy_idx;
		}
		if (((*str_cpy)[++str_cpy_idx] == c && ret))
			(*str_cpy)[str_cpy_idx] = '_';
		++str;
	}
	return (ret);
}
