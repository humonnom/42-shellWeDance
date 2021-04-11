#include "../incs/minishell.h"

// devide cmd, args tokens by ;
// return line_list as linked_list form
t_list	*gen_line_list(char *line)
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
	if (!error_num && set_darr_to_list(&ret, line_part))
		error_num = turn_on_bit(error_num, 2);
	free (line_cpy);
	if (!check_bit(error_num, 1))
		free_darr(line_part, INF);
	if (error_num)
		return (NULL);
	return (ret);
}
