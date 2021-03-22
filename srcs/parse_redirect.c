#include "../incs/minishell.h"

static char	*cut_off_redir(char *str, int len)
{
	char *ret;

	ret = ft_substr(str, 0, len);
	free(str);
	return (ret);
}

char	*parse_redirect(t_info *info, char *str)
{
	char	*str_cpy;
	char	*tmp;
	int		tmp_ret;
	int		type;
	int		idx;
	int		cut_point;

	idx = 0;
	tmp_ret = 1;
	cut_point = -1;

	str_cpy = ft_strdup("");
	while (tmp_ret > 0 && str[idx])
	{
		tmp_ret = 1;
		printf("[%c]\n", str[idx]);
		type = is_bracket(str[idx], str[idx + 1]);
		if (type)
		{
			printf("bracket ==> str[%d] : %c\n", idx, str[idx]);
			// if set_redirct_info fail for some reason, return -1.
			tmp_ret = set_redir_info(info, &str[idx], type);
			// if it's first redirection signal, record idx as cut point.
		}
		else
		{
			tmp = ft_strjoin(str_cpy, str[idx]);
			free(str_cpy);
			str_cpy = tmp;
		}
		idx += tmp_ret;
	}
	// if there is (a) redirection signal(s), cut off string. 
	str = str_cpy;
	return (str);
}
