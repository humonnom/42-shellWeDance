#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
extern int get_next_line(char **line);
extern int handle_quote(char *str, char **str_cpy, char c);

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

//exclude dquote or squote in arg_lst head
int			trim_cmd(t_list *arg_list)
{
	char	*cmd;
	if (!(cmd = copy_without_quote(arg_list->data)))
		return (1);
	free(arg_list->data);
	arg_list->data = cmd;
    return (0);
}
