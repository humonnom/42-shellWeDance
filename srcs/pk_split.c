#include "minishell.h"

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

static char		**free_all(char **tab, int k)
{
	int	idx;

	idx = 0;
	while (idx < k)
	{
		free(tab[idx]);
		++idx;
	}
	free(tab);
	return (NULL);
}

char			**pk_split(
				const char *s,
				const char *s_cpy,
				char c)
{
	char	**ret;
	int		begin;
	size_t	len_word;
	size_t	size;
	size_t	k;

	if (s == NULL)
		return (0);
	size = get_size(s_cpy, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = 0;
	k = 0;
	begin = 0;
	while (k < size)
	{
		begin = get_next_idx(s_cpy, begin, &len_word, c);
		if (!(ret[k] = (char *)malloc(sizeof(char) * (len_word + 1))))
			return (free_all(ret, k));
		ft_strlcpy(ret[k], &s[begin], len_word + 1);
		begin = begin + len_word;
		++k;
	}
	return (ret);
}
