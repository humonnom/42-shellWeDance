#include "../incs/minishell.h"

static char	*show_type_error(char *str)
{
	char	c[2];

	show_error("parse error near");
	show_error(" `");
	c[0] = str[0];
	c[1] = '\0';
	show_error(c);
	if (str[1] && is_bracket(str[1]))
	{
		c[0] = str[1];
		c[1] = '\0';
		show_error(c);
	}
	show_error("'\n");
	return (NULL);
}

static int	join_char_to_args(char **str, char c, int *idx)
{
	int		ret;
	char	*tmp;
	char	*c_str;

	c_str = cvt_char_to_str(c);
	tmp = ft_strjoin(*str, c_str);
	if (!tmp)
		return (0);
	free(c_str);
	free(*str);
	*str = tmp;
	*idx += 1;
	return (1);
}

static char	*set_tokens_type(
			t_tokens *tokens,
			char *str,
			char *str_cpy)
{
	char	*ret;
	int		idx;
	int		tmp_type;
	int		inc_flag;

	idx = 0;
	inc_flag = 1;
	ret = ft_strdup("");
	while (inc_flag && str_cpy[idx])
	{
		inc_flag = 1;
		tmp_type = set_bracket_type(&str_cpy[0], &idx);
		tokens->type |= tmp_type;
		if (tokens->type & TYPE_ERROR)
			return (show_type_error(&str_cpy[idx]));
		if (tmp_type & (TYPE_REIN | TYPE_REOUT | TYPE_REOUT_D))
			inc_flag = open_valid_fd(tokens, &str_cpy[idx], &idx, tmp_type);
		else
			inc_flag = join_char_to_args(&ret, str[idx], &idx);
	}
	if (inc_flag == 0)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*set_fd(t_tokens *tokens, char *line)
{
	char	*ret;
	char	*line_cpy;

    line_cpy = ft_strdup(line);
	handle_quote(line, &line_cpy, ' ');
	handle_quote(line_cpy, &line_cpy, '<');
	handle_quote(line_cpy, &line_cpy, '>');
	tokens->type = 0;
	tokens->fd_in_idx = -1;
	tokens->fd_out_idx = -1;
	ret = set_tokens_type(tokens, line, line_cpy);
	free(line_cpy);
	return (ret);
}
