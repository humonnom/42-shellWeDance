#include "../incs/minishell.h"

static int	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

static int	get_cmd_size(char *str)
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

static char *copy_without_quote(char *str)
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

int		trim_cmd(t_info *info)
{
	char	*ret;
	char	*cmd;

	cmd = info->set->set[0];
	if (!(ret = copy_without_quote(cmd)))
		return (1);
	free(cmd);
	info->set->set[0] = ret;
	info->set->cmd = info->set->set[0];
    return (0);
}

