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
	{
		c[0] = str[1];
		c[1] = '\0';
		show_error(c);
	}
	show_error("'\n");
	return (NULL);
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
		if (type == TYPE_REIN || type == TYPE_REOUT || type == TYPE_REOUT_D)
		{
			idx_inc = set_redir_info(info, &str_cpy[idx], type);
			idx += idx_inc;
		}
		else
		{
			tmp_char = cvt_char_to_str(str[idx]);
			tmp = ft_strjoin(ret, tmp_char);
			free(tmp_char);
			free(ret);
			ret = tmp;
			++idx;
		}
	}
	printf("parse_redir::ret: %s\n", ret);
#if 0 
	while (step > 0 && *str_cpy)
	{
		type = set_bracket_type(&str_cpy);
		if (type == TYPE_ERROR)
		{
//			printf("zsh: parse error near `%c", filename[0]);
//			if (tmp_type == TYPE_REOUT_D)
//				printf("%c", filename[1]);
//			printf("'\n");
			return (NULL);
		}
		if (type == TYPE_REIN || type == TYPE_REOUT || type == TYPE_REOUT_D)
		{
			printf("bracket ==> str_cpy[%d] : %c\n", idx, str[idx]);
			step = set_redir_info(info, &str_cpy[idx], type);
			(*str_cpy) += step;
		}
		else
		{
			tmp_char = cvt_char_to_str(str[idx]);
			tmp = ft_strjoin(ret, tmp_char);
			free(tmp_char);
			free(ret);
			ret = tmp;
			++(*str_cpy);
		}
	}
#endif
	return (ret);
}
