#include "../incs/minishell.h"

static char	*get_str_by_inst_arr(long inst_arr[], int inst_arr_size)
{
	int		inst_arr_idx;
	char	*ret;
	char	*tmp_ret;
	int		tmp_ret_idx;

	tmp_ret = (char *)malloc(sizeof(char) * (inst_arr_size + 1));
	tmp_ret[inst_arr_size] = '\0';
	tmp_ret_idx = 0;
	inst_arr_idx = -1;
	while (++inst_arr_idx < inst_arr_size)
	{
		if (inst_arr[inst_arr_idx] == KEY_BACKSPACE)
		{
			tmp_ret_idx = calc_max(tmp_ret_idx - 1, 0);
			tmp_ret[tmp_ret_idx] = '\0';
		}
		else if (inst_arr[inst_arr_idx] == KEY_LEFT_ARROW)
			continue ;
		else if (inst_arr[inst_arr_idx] == KEY_RIGHT_ARROW)
			continue ;
		else
			tmp_ret[tmp_ret_idx++] = (char)inst_arr[inst_arr_idx];
	}
	ret = ft_substr(tmp_ret, 0, tmp_ret_idx);
	free(tmp_ret);
	printf("\n\nret: %s\n", ret);
	return (ret);
}

static int	join_history_line(
			const t_info *info,
			long inst_arr[])
{
	int		ret;
	char	*str_out;

	ft_cursor_clr_line_all(info->tc);
	ft_cursor_mv_head(info->tc);

	str_out = "NEW LINE";

	write(1, info->prompt.data, info->prompt.size);
	ret = -1;
	while (++ret < ft_strlen(str_out))
	{
		inst_arr[ret] = (long)str_out[ret];
	}
	return (ret);
}

static int	handle_key_arrow(
			const t_info *info,
			long arr[],
			long c,
			int cursor_right_limit)
{
	int	ret;

	ret = 0;
	if (c == KEY_LEFT_ARROW)
		ft_cursor_mv_left(info->tc.cursor.col, info->prompt.size);
	else if (c == KEY_RIGHT_ARROW)
		ft_cursor_mv_right(info->tc.cursor.col, cursor_right_limit);
	else if (c == KEY_UP_ARROW)
		ret = join_history_line(info, arr) - 1;
	return (ret);
}

// return size of inst_arr
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
			idx += handle_key_arrow(info, arr, c, info->prompt.size + buf_len);
		else if (c == KEY_BACKSPACE && --buf_len)
			ft_cursor_clr_line_end(info->tc, info->prompt.size);
		c = 0;
	}
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
	write(1, info->prompt.data, info->prompt.size);
	ft_memset(inst_arr, 0, BUFFER_SIZE);
	inst_arr_size = set_inst_arr_in_loop(info, inst_arr);
	ret = get_str_by_inst_arr(inst_arr, inst_arr_size);
	return (ret);	
}
