#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
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
	printf("ret_size: %d\n", ret_size);
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
	//free(str);
	return (ret);
}

#if 1
static int	trim_cmd(t_list *arg_list)
{
	int	ret;

	ret = 0;
	printf("str: %s\n", (char *)(arg_list->content));
    //1. check if s/dquote is open or pair
	if ((ret = handle_quote(arg_list->content, )))
		return (ret);
    //2. exclude dquote or squote in arg_lst head
	if (!(arg_list->content = copy_without_quote(arg_list->content)))
		return (ret);
	printf("modified head: %s\n", (char *)(arg_list->content));
	
    return (ret);
}
#endif

int main() {
//	char *line;
//	get_next_line(&line);
	t_list	arg_list;

	// "a's""fasd'f"
	char *line = "\"e\'c\"\"\'ho\'\'\"       \"ab \'    \'   cd\"";
	arg_list.content = line;
	arg_list.next = NULL;

	//printf("result: %d\n", trim_cmd(&arg_list));
	char *line_cpy;
	printf("line    : %s\n", line);
	if (!(line_cpy = ft_strdup(line)))
		return (-1);
	handle_quote(line, &line_cpy, ' ');
	printf("line_cpy: %s\n", line_cpy);
	return (0);
}
