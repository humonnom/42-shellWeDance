#include "../incs/minishell.h"

t_list	*gen_slist(t_info *info, char **str)
{
	int		idx;
	t_set	*tmp_set;
	t_list	*ret;

	ret = NULL;
	idx = -1;
	while (str[++idx])
	{
		tmp_set = gen_set(info, str[idx]);
		if (tmp_set == NULL)
		{
			ft_lstclear(&ret, &free_set);
			return (NULL);
		}
		else
		{
			if (str[idx + 1] == NULL)
				tmp_set->type |= TYPE_BREAK;
			else
				tmp_set->type |= TYPE_PIPE;
			ft_lstadd_back(&ret, ft_lstnew(tmp_set));
		}
	}
	return (ret);
}

t_list			*gen_set_list(t_info *info)
{
	char	*line;
	char	*line_cpy;
	char	**line_part;
	t_list	*ret;
	int		error_num;

	line = info->set_str_list->data;
	ret = NULL;
	error_num = 0;
	if (!(line_cpy = ft_strdup(line)))
		return (NULL);
	if (handle_quote(line, &line_cpy, '|'))
		error_num = turn_on_bit(error_num, 0);
	if (!(line_part = pk_split(line, line_cpy, '|', INF)))
		error_num = turn_on_bit(error_num, 1);
	ret = gen_slist(info, line_part);	
	free (line_cpy);
	if (!check_bit(error_num, 1))
		free_darr(line_part, INF); 
	if (error_num)
		return (NULL);
	return (ret);
}
