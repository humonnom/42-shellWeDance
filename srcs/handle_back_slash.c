#include "../incs/minishell.h"

static int
	get_back_slash_len(char *str, char c)
{
	int		idx;
	int		len;

	idx = -1;
	len = 0;
	while (str[++idx])
	{
		if (str[idx] == c && str[idx + 1] == '\0')
			return (-1);
		if (str[idx] == c && str[idx + 1] != '\0')
		{
			len += 3;
			idx++;
		}
		else
			len++;
	}
	return (len);
}

static char
	select_quote(char target)
{
	char	single_quote;
	char	double_quote;

	single_quote = '\'';
	double_quote = '\"';
	if (target == single_quote)
		return(double_quote);
	return (single_quote);
}

static void
	cvt_back_slash_to_quote(char *str, char *ret, char c)
{
	int		len;
	int		idx;
	int		ret_idx;
	char	quote;
	
	idx = -1;
	ret_idx = -1;
	while (str[++idx] && ++ret_idx < len)
	{
		if (str[idx] == c)
		{
			quote = select_quote(str[idx + 1]);
			ret[ret_idx] = quote;
			ret[++ret_idx] = str[++idx];
			ret[++ret_idx] = quote;
		}
		else
			ret[ret_idx] = str[idx];
	}
}

char
	*handle_back_slash(
	char *str,
	char c)
{
	char	*ret;
	int		len;

	if ((len = get_back_slash_len(str, c)) == -1)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	cvt_back_slash_to_quote(str, ret, c);
	return (ret);
}
