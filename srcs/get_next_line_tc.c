#include "../incs/minishell.h"

extern int	g_signal;

static int	handle_sig_in_gnl(t_info *info, long *arr, long *c, int *idx, int *buf_len)
{
	if (g_signal == SIG_SIGINT)
	{
		ft_memset(arr, 0, BUFFER_SIZE);
		*buf_len = 0;
		*idx = -1;
		g_signal = OFF;
		return (1);
	}
	else if (*c == 4 && *buf_len == 0)
		exit_shell(info);
	else if (*c == 4 && *buf_len != 0)
		*c = 4500001;
	return (0);
}

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
	ft_memset(inst_arr, 0, BUFFER_SIZE);
	if (key_arrow == KEY_UP_ARROW && info->history_ptr->next != NULL)
		info->history_ptr = info->history_ptr->next;
	if (key_arrow == KEY_DOWN_ARROW && info->history_ptr->prev != NULL)
		info->history_ptr = info->history_ptr->prev;
	history_line = (char *)(info->history_ptr->data);
	ft_putstr_fd(PROMPT_DATA, STDOUT_FILENO);	
	ft_putstr_fd(history_line, STDOUT_FILENO);
	ret = -1;
	while (++ret < ft_strlen(history_line))
		inst_arr[ret] = (long)history_line[ret];
	return (ret);
}

static int	handle_key_arrow(
			t_info *info,
			long arr[],
			long c,
			int right_limit)
{
	int		ret;
	char	*tmp;

	if (info->history_ptr == NULL)
		return (0);
	ret = 0;
#if 0
	if (c == KEY_LEFT_ARROW)
		ft_cursor_mv_left(info->tc.cursor.col, PROMPT_SIZE);
	else if (c == KEY_RIGHT_ARROW)
		ft_cursor_mv_right(info->tc.cursor.col, right_limit);
#endif
	if (c == KEY_UP_ARROW || c == KEY_DOWN_ARROW)
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
	while ((read(STDIN_FILENO, &c, sizeof(c))) > 0 && (c != '\n'))
	{
		//handle_sig_in_gnl(info, arr, &c, &idx, &buf_len);
		get_cursor_pos(&(info->tc.cursor.col), &(info->tc.cursor.row));
		if (c <= 4500000)
			arr[++idx] = c;
		if (ft_isprint(c))
		{
			++buf_len;
			ft_putchar_fd(c, STDOUT_FILENO);
		}
		else if (is_key_arrow(c))
			idx = handle_key_arrow(info, arr, c, PROMPT_SIZE + buf_len);
		else if (c == KEY_BACKSPACE)
		{
			buf_len = calc_max(--buf_len, 0);
			ft_cursor_clr_line_end(info->tc, PROMPT_SIZE);
		}
		c = 0;
	}
	if (c == '\n')
		ft_putstr_fd("\n", STDOUT_FILENO);
#if 0
	if (g_signal)
		handle_sig_in_gnl(info, arr, &c, &idx, &buf_len);
#endif
	return (idx + 1);
}

char	*get_next_line_tc(t_info *info)
{
	t_tc	tc;
	char	*ret;
	long	inst_arr[BUFFER_SIZE];
	int		inst_arr_size;

	ret = NULL; 
	tc = info->tc;
	get_cursor_pos(&tc.cursor.col, &tc.cursor.row);
	ft_cursor_mv_head(tc);
	ft_putstr_fd(PROMPT_DATA, STDOUT_FILENO);
	ft_memset(inst_arr, 0, BUFFER_SIZE);
	inst_arr_size = set_inst_arr_in_loop(info, inst_arr);
	if (inst_arr[0] != 0)
		ret = get_str_by_inst_arr(inst_arr, inst_arr_size);
	return (ret);
}
