#define BIT_SQUOTE 1
#define BIT_DQUOTE 2
#define ON 0x00001
#define OFF 0x00000

static int	turn_on_bit(int val, int n)
{
	return (val |= (1 << n));
}

static int	turn_off_bit(int val, int n)
{
	return (val &= ~(1 << n));
}

static int	check_bit(int val, int n)
{
	if ((val >> n) & ON)
		return (ON);
	return (OFF);
}

static int	handle_squote_in_dquote(int val)
{
	int	ret;

	if (check_bit(val, BIT_DQUOTE))
		ret = turn_off_bit(val, BIT_SQUOTE);
	else
		ret = turn_on_bit(ret, BIT_SQUOTE);
	return (ret);
}

static int	handle_dquote_in_squote(int val)
{
	int	ret;

	if (check_bit(val, BIT_SQUOTE))
		ret = turn_off_bit(val, BIT_DQUOTE);
	else
		ret = turn_on_bit(ret, BIT_DQUOTE);
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
