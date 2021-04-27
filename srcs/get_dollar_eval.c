/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar_eval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:13 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:44:28 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

static int
	is_finish_cond(char c)
{
	if (c == '\"')
		return (1);
	if (c == '\'')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '/')
		return (1);
	return (0);
}

static int
	get_word_len(char *part)
{
	int	ret;

	ret = 0;
	while (part[ret])
	{
		if (is_finish_cond(part[ret]))
			return (ret);
		++ret;
	}
	return (ret);
}

char
	*get_dollar_eval(char *part, t_list *env_list, int *idx)
{
	char	*ret;
	int		word_len;
	char	*tmp_key;

	if (part[0] != '$')
		return (NULL);
	word_len = get_word_len(part);
	if (word_len == 1)
	{
		*idx = *idx + word_len;
		return (ft_strdup("$"));
	}
	if (exact_strncmp("$?", part) == 0)
	{
		*idx = *idx + word_len;
		return (ft_itoa(g_signal));
	}
	tmp_key = ft_substr(part, 1, word_len - 1);
	ret = ft_strdup(get_eval(env_list, tmp_key));
	*idx = *idx + word_len;
	free(tmp_key);
	tmp_key = NULL;
	return (ret);
}
