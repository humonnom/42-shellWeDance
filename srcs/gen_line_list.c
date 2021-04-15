#include "../incs/minishell.h"

// devide cmd, args tokens by ;
// return line_list as linked_list form
#if 0
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
#endif

static int
	is_valid_line_arr(char **line_arr)
{
	if (line_arr == 0 || line_arr[0] == 0)
		return (1);
	return (0);
}

static t_list
	*handle_invalid_line_arr(char **line_arr)
{
	if (line_arr == 0)
		printf("ERROR: MALLOC IS FAILED\n");
	return (NULL);
}

t_list	*gen_line_list(char *line)
{
	char	*line_cpy;
	char	**line_arr;
	t_list	*ret;

	ret = NULL;
	if (!(line_cpy = ft_strdup(line)))
		return (NULL);
	handle_quote(line, &line_cpy, ';');
	line_arr = pk_split(line, line_cpy, ';', INF);
	free (line_cpy);
	if (is_valid_line_arr(line_arr))
		return (handle_invalid_line_arr(line_arr));
	if(set_darr_to_list(&ret, line_arr))
		return (NULL);
	free_darr(line_arr, INF);
	return (ret);
}
