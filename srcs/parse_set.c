#include "../incs/minishell.h"

static t_list	*gen_slist(char **str)
{
	int		error_num;
	int		idx;
	t_set	*tmp_set;
	t_list	*ret;

	ret = NULL;
	error_num = 0;
	idx = -1;
	while (error_num == 0 && str[++idx])
	{
		if (!(tmp_set = get_set(str[idx])))
			error_num = 1;
		if (str[idx + 1] == 0)
			tmp_set->type = TYPE_BREAK;
		else
			tmp_set->type = TYPE_PIPE;
		ft_lstadd_back(&ret, ft_lstnew(tmp_set));
	}
	return (ret);
}

t_list			*parse_set(char *line)
{
	char	*line_cpy;
	char	**line_part;
	t_list	*ret;
	int		error_num;

	ret = NULL;
	error_num = 0;
	if (!(line_cpy = ft_strdup(line)))
		return (NULL);
	if (handle_quote(line, &line_cpy, '|'))
		error_num = turn_on_bit(error_num, 0);
	if (!(line_part = pk_split(line, line_cpy, '|', INF)))
		error_num = turn_on_bit(error_num, 1);
	ret = gen_slist(line_part);	
	free (line_cpy);
	if (!check_bit(error_num, 1))
		free_darr(line_part, INF);
	if (error_num)
		return (NULL);
	return (ret);
}
