#include "../incs/minishell.h"
#if 0
int is_bracket(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] && str[idx] == '>' && idx < 2)
		idx++;
	if (str[idx] == '>')
		return (TYPE_ERROR);
	if (idx == 1)
		return (TYPE_REOUT);
	if (idx == 2)
		return (TYPE_REOUT_D);
	if (str[idx] == '<' && str[idx + 1] != '<')
		return (TYPE_REIN);
	else if (str[idx] == '<' && str[idx + 1] == '<')
		return (TYPE_ERROR);
	return (0);
}
#endif
#if 0
static int	is_bracket_error(
			char **str,
			char bracket,
			int *cnt)
{
	while (**str && **str == bracket && (*cnt)--)
		++(*str);
	if (**str == bracket)
		return (TYPE_ERROR);
	return (0);
}

int set_bracket_type(char **str_addr)
{
	char	*str;
	int		ret;
	int		cnt;

	str = *str_addr;
	cnt = 2;
	is_bracket_error(&str, '>', &cnt);
	*str_addr = str;
	if (cnt == 1)
		return (TYPE_REOUT);
	if (cnt == 0)
		return (TYPE_REOUT_D);
	cnt = 1;
	is_bracket_error(&str, '<', &cnt);
	*str_addr = str;
	if (cnt == 0)
		return (TYPE_REIN);
	return (0);
}
#endif

static int	is_bracket_error(
			char *str,
			int *idx,
			char bracket,
			int *cnt)
{
	while (str[*idx] && str[*idx] == bracket && (*cnt)--)
		++(*idx);
	if (str[*idx] == bracket)
		return (TYPE_ERROR);
	return (0);
}

int set_bracket_type(char *str, int *idx)
{
	int		ret;
	int		cnt;

	cnt = 2;
	if (is_bracket_error(str, idx, '>', &cnt))
		return (TYPE_ERROR);
	if (cnt == 1)
		return (TYPE_REOUT);
	if (cnt == 0)
		return (TYPE_REOUT_D);
	cnt = 1;
	if (is_bracket_error(str, idx, '<', &cnt))
		return (TYPE_ERROR);
	if (cnt == 0)
		return (TYPE_REIN);
	return (0);
}
