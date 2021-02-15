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
	int	tmp_flag;

	ret = 0;
	str_cpy_idx = -1;
	while (*str)
	{
		// when DQUOTE is opened, SQUOTE is useless as str starter
		if (!check_bit(ret, BIT_SQUOTE) && *str == '\'')
			ret = handle_squote_in_dquote(ret);
		else if (!check_bit(ret, BIT_DQUOTE) && *str == '\"')
			ret = handle_dquote_in_squote(ret);
		else if (check_bit(ret, BIT_SQUOTE) && *str == '\'')
			ret = turn_off_bit(ret, BIT_SQUOTE);
		else if (check_bit(ret, BIT_DQUOTE) && *str == '\"')
			ret = turn_off_bit(ret, BIT_DQUOTE);
		// when SQUOTE or DQUOTE is on
		if (((*str_cpy)[++str_cpy_idx] == c && ret))
			(*str_cpy)[str_cpy_idx] = '_';
		++str;
	}
	return (ret);
}
