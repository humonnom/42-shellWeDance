#include "../incs/minishell.h"

static char	*get_str_by_inst_arr(long inst_arr[], int inst_arr_size)
{
	int		idx;
	char	*ret;
	char	*tmp_ret;
	int		tmp_ret_idx;

	tmp_ret = (char *)malloc(sizeof(char) * (inst_arr_size + 1));
	tmp_ret[inst_arr_size] = '\0';
	tmp_ret_idx = 0;
	idx = -1;
	while (++idx < inst_arr_size)
	{
		if (inst_arr[idx] == KEY_BACKSPACE)
		{
			tmp_ret_idx = calc_max(tmp_ret_idx - 1, 0);
			tmp_ret[tmp_ret_idx] = '\0';
		}
		else if (is_key_arrow(inst_arr[idx]))
			continue ;
		else
			tmp_ret[tmp_ret_idx++] = (char)inst_arr[idx];
	}
	ret = ft_substr(tmp_ret, 0, tmp_ret_idx);
	free(tmp_ret);
	return (ret);
}

static int	join_history_line(
			t_info *info,
			long inst_arr[],
			long key_arrow)
{
	int		ret;
	char	*history_line;

	ft_cursor_clr_line_all(info->tc);
	ft_cursor_mv_head(info->tc);
	ft_memset(inst_arr, 0, BUFFER_SIZE);
	if (key_arrow == KEY_UP_ARROW && info->history_ptr->next != NULL)
		info->history_ptr = info->history_ptr->next;
	if (key_arrow == KEY_DOWN_ARROW && info->history_ptr->prev != NULL)
		info->history_ptr = info->history_ptr->prev;
	history_line = (char *)(info->history_ptr->data);
	write(1, info->prompt.data, info->prompt.size);
	ft_putstr_fd(history_line, 1);
	ret = -1;
	while (++ret < ft_strlen(history_line))
		inst_arr[ret] = (long)history_line[ret];
	return (ret);
}

static int	handle_key_arrow(
			t_info *info,
			long arr[],
			long c,
			int cursor_right_limit)
{
	int		ret;
	char	*tmp;

	if (info->history_ptr == NULL)
		return (0);
	ret = 0;
	if (c == KEY_LEFT_ARROW)
		ft_cursor_mv_left(info->tc.cursor.col, info->prompt.size);
	else if (c == KEY_RIGHT_ARROW)
		ft_cursor_mv_right(info->tc.cursor.col, cursor_right_limit);
	else if (c == KEY_UP_ARROW || c == KEY_DOWN_ARROW)
		ret = join_history_line(info, arr, c) - 1;
	return (ret);
}

static int	set_inst_arr_in_loop(
			t_info *info,
			long *arr)
{
	long	c;
	int		buf_len;
	int		idx;

	buf_len = 0;
	idx = -1;
	c = 0;
	while ((read(STDIN_FILENO, &c, sizeof(c)) > 0) && (c != '\n'))
	{
		get_cursor_pos(&(info->tc.cursor.col), &(info->tc.cursor.row));
		if (c <= 4500000)
			arr[++idx] = c;
		if (ft_isprint(c) && ++buf_len)
			ft_putchar_fd(c, 1);
		else if (is_key_arrow(c))
			idx = handle_key_arrow(info, arr, c, info->prompt.size + buf_len);
		else if (c == KEY_BACKSPACE && --buf_len)
			ft_cursor_clr_line_end(info->tc, info->prompt.size);
		c = 0;
	}
	if (c == '\n')
		write(STDOUT_FILENO, &c, 1);
	return (idx + 1);
}

char	*get_next_line_tc(t_info *info)
{
	t_tc	tc;
	char	*ret;
	long	inst_arr[BUFFER_SIZE];
	int		inst_arr_size;

	tc = info->tc;
	get_cursor_pos(&tc.cursor.col, &tc.cursor.row);
	ft_cursor_mv_head(tc);
	write(STDOUT_FILENO, info->prompt.data, info->prompt.size);
	ft_memset(inst_arr, 0, BUFFER_SIZE);
	inst_arr_size = set_inst_arr_in_loop(info, inst_arr);
	ret = get_str_by_inst_arr(inst_arr, inst_arr_size);
	return (ret);
}
