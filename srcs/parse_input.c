#include "minishell.h"

static int		get_lines(
				t_lst *line_lst,
				char *line)
{
	char 	**lines;
	char	*tmp_line;
	int		len;

	if ((lines = split_lines(line, ';')) == 0)
		return -1;
	len = 0;
	while (lines[len])
		len++;
	while (lines[--len])
	{
		tmp_line = ft_strdup(lines[len]);
		ft_lstadd_front(&line_lst, ft_lstnew(tmp_line));
	}
	free_split(lines);
}

int				parse_input(t_lst *line_lst)
{
	char *line;

	if (line_lst == NULL)
	{
		if ((get_next_line(&line)) == -1)
			return -1;
		if (check_dquote(line, DQUOTE_OPEN))
			return -1;
		if (check_dquote(line, DQUOTE_COPY))
			return -1;
		if (get_lines(line_lst, line) == -1)
			return -1;
	}
	return 0;
}
