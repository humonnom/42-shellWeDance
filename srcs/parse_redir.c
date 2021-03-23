#include "../incs/minishell.h"

static char	*show_type_error(char *str)
{
	char	c[2];

	show_error("zsh: parse error near");
	show_error(" `");
	c[0] = str[0];
	c[1] = '\0';
	show_error(c);
	if (str[1] && is_bracket(str[1]))
	{ c[0] = str[1];
		c[1] = '\0';
		show_error(c);
	}
	show_error("'\n");
	return (NULL);
}

static int	join_char_to_args(char **str, char c)
{
	int		ret;
	char	*tmp;
	char	*c_str;

	c_str = cvt_char_to_str(c);
	tmp = ft_strjoin(*str, c_str);
	free(c_str);
	free(*str);
	*str = tmp;
	return (1);
}

char	*parse_redir(t_info *info, char *str, char *str_cpy)
{
	char	*ret;
	char	*tmp;
	char	*tmp_char;
	int		type;
	int		idx;
	int		idx_inc;

	idx = 0;
	idx_inc = 1;
	ret = ft_strdup("");
	while (idx_inc > 0 && str_cpy[idx])
	{
		type = set_bracket_type(&str_cpy[0], &idx);
		if (type == TYPE_ERROR)
			return (show_type_error(&str_cpy[idx]));
		if (type == TYPE_REIN \
			|| type == TYPE_REOUT || type == TYPE_REOUT_D)
			idx_inc = set_redir_info(info, &str_cpy[idx], type);
		else
			idx_inc = join_char_to_args(&ret, str[idx]);
		idx += idx_inc;
	}
	printf("parse_redir::ret: %s\n", ret);
	return (ret);
}
