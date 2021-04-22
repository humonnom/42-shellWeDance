/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:35 by juepark           #+#    #+#             */
/*   Updated: 2021/04/22 16:39:20 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static char
	*handle_nquote_part(
	char **str_addr,
	t_list *env_list)
{
	int		idx;
	char	*str;
	char	*prev_ret;
	char	*tmp;
	char	*ret;

	str = *str_addr;
	idx = 0;
	if (is_dquote(str[idx]) || is_squote(str[idx]))
		return (NULL);
	ret = ft_strdup("");
	prev_ret = ret;
	while (!is_dquote(str[idx]) && !is_squote(str[idx]) && str[idx])
	{
		if (str[idx] == '$')
			tmp = get_dollar_eval(&str[idx], env_list, &idx);
		else
			tmp = cvt_char_to_str(str[idx++]);
		ret = ft_strjoin(ret, tmp);
		free(prev_ret);
		prev_ret = ret;
		free(tmp);
	}
	*str_addr = *str_addr + idx;
	return (ret);
}

static char
	*handle_squote_part(char **str_addr)
{
	int		idx;
	char	*str;
	char	*ret;

	str = *str_addr;
	idx = 0;
	if (!is_squote(str[idx++]))
		return (NULL);
	while (!is_squote(str[idx]))
		++idx;
	ret = ft_substr(str, 1, idx - 1);
	*str_addr = *str_addr + idx;
	return (ret);
}

static char
	*handle_dquote_part(
	char **str_addr,
	t_list *env_list)
{
	int		idx;
	char	*str;
	char	*prev_ret;
	char	*tmp;
	char	*ret;

	str = *str_addr;
	idx = 0;
	if (!is_dquote(str[idx++]))
		return (NULL);
	ret = ft_strdup("");
	prev_ret = ret;
	while (!is_dquote(str[idx]))
	{
		if (str[idx] == '$')
			tmp = get_dollar_eval(&str[idx], env_list, &idx);
		else
			tmp = cvt_char_to_str(str[idx++]);
		ret = ft_strjoin(ret, tmp);
		free(prev_ret);
		prev_ret = ret;
		free(tmp);
	}
	*str_addr = *str_addr + idx;
	return (ret);
}

char
	*handle_arg(char *arg, t_list *env_list)
{
	char	*ret;
	char	*prev_ret;
	char	*tmp;

	ret = ft_strdup("");
	prev_ret = ret;
	while (arg && *arg)
	{
		if (is_dquote(*arg))
			tmp = handle_dquote_part(&arg, env_list);
		else if (is_squote(*arg))
			tmp = handle_squote_part(&arg);
		else
		{
			tmp = handle_nquote_part(&arg, env_list);
			if (*arg == '\0')
				--arg;
		}
		ret = ft_strjoin(ret, tmp);
		free(prev_ret);
		prev_ret = ret;
		free(tmp);
		++arg;
	}
	return (ret);
}
