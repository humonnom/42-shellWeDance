#include "../incs/minishell.h"

static int	get_slist(
			t_list **list_head,
			char **str)
{
	int		ret;
	int		len;
	t_list	*tmp_list;
	char	*tmp_set;

	ret = 0;	
	len = 0;
	while (ret == 0 && str[len])
		len++;
	while (ret == 0 && --len >= 0)
	{
		if (!(tmp_set = ft_strdup(str[len])))
			ret = 1;
		tmp_list = ft_lstnew(tmp_set);
		ft_lstadd_front(list_head, tmp_list);
	}
	return (ret);
}

// devide cmd, args set by ;
// return line_list as linked_list form
t_list	*parse_line(char *line)
{
	char	*line_cpy;
	char	**line_part;
	t_list	*ret;
	int		error_num;

	ret = NULL;
	error_num = 0;
	if (!(line_cpy = ft_strdup(line)))
		return (NULL);
	if (handle_quote(line, &line_cpy, ';'))
		error_num = turn_on_bit(error_num, 0);
	if (!(line_part = pk_split(line, line_cpy, ';', INF)))
		error_num = turn_on_bit(error_num, 1);
	if (!error_num && get_slist(&ret, line_part))
		error_num = turn_on_bit(error_num, 2);
	free (line_cpy);
	if (!check_bit(error_num, 1))
		free_darr(line_part, INF);
	if (error_num)
		return (NULL);
	return (ret);
}

#if 0
$ echo "abc ; " ; cd ~ ;

1. line in gnl  : echo "abc ; " b c ; cd ~ 
2. line_cpy     : echo "abc 0 " b c ; cd ~ 
3. split_lines  : [echo "abc ; " b c, cd ~ ]
4. get_line_lst : {echo "abc"} -> {cd ~} 
#endif
