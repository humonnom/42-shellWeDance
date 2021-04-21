/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pk_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:19:07 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 11:33:43 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static size_t	get_size(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		while ((*s != '\0') && (*s == c))
			++s;
		if ((*s != '\0') && (*s != c))
			++ret;
		while ((*s != '\0') && (*s != c))
			++s;
	}
	return (ret);
}

static int		get_next_idx(
				const char *s,
				int begin,
				size_t *len_word,
				char c)
{
	int	idx;
	int	ret;

	ret = begin;
	while ((s[ret] != '\0') && (s[ret] == c))
		ret++;
	*len_word = 0;
	idx = ret;
	while ((s[idx] != '\0') && (s[idx] != c))
	{
		++(*len_word);
		++idx;
	}
	return (ret);
}

char			**pk_split(
				const char *s,
				const char *s_cpy,
				char c,
				int limit)
{
	char	**ret;
	int		begin;
	size_t	len_word;
	size_t	size;
	size_t	k;

	if (s == NULL)
		return (0);
	size = get_size(s_cpy, c);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (0);
	ret[size] = 0;
	k = -1;
	begin = 0;
	while (++k < size && limit--)
	{
		begin = get_next_idx(s_cpy, begin, &len_word, c);
		ret[k] = (char *)malloc(sizeof(char) * (len_word + 1));
		if (!ret[k])
			return (free_darr(ret, k));
		ft_strlcpy(ret[k], &s[begin], len_word + 1);
		begin = begin + len_word;
	}
	return (ret);
}
