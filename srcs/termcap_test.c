#include "../incs/minishell.h"

static t_tc	gen_tc()
{
	t_tc	ret;

	tcgetattr(STDIN_FILENO, &(ret.term));
	ret.term.c_lflag &= ~ICANON;
	ret.term.c_lflag &= ~ECHO;
	ret.term.c_cc[VMIN] = 1;
	ret.term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &(ret.term));

	ret.cursor.row = 0;
	ret.cursor.col = 0;

	tgetent(NULL, "xterm");
	ret.tc_str[TC_CM] = tgetstr("cm", NULL); 
	ret.tc_str[TC_DL] = tgetstr("dl", NULL); 
	ret.tc_str[TC_CE] = tgetstr("ce", NULL); 

	return (ret);
}


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

static int	handle_up_arrow(t_tc tc, long inst_arr[], int inst_arr_size)
{
	int		idx;
	char	*str_out;

	ft_cursor_clr_line_all(tc.tc_str, tc.cursor.row);
	ft_cursor_mv_head(tc.tc_str, tc.cursor.row);

	str_out = "NEW LINE";
	
	char	*prompt = ">> ";
	write(1, prompt, ft_strlen(prompt));
	ft_putstr_fd(str_out, 1);
	idx = -1;
	while (++idx < ft_strlen(str_out))
	{
		inst_arr[idx] = (long)str_out[idx];
	}
	return (idx);
}

char	*get_next_line_tc()
{

	return (0);
}

int		test(t_info *info, t_prompt prompt)
{
	t_tc	tc;
	long	inst_arr[BUFFER_SIZE];
	int		inst_arr_idx;
	char	*ret;
	long	c;

	tc = gen_tc();
	while (1)
	{
		c = 0;
		get_cursor_pos(&tc.cursor.col, &tc.cursor.row);
		ft_cursor_mv_head(tc.tc_str, tc.cursor.row);
		write(1, prompt.data, prompt.size);
		int buf_len = 0;
		ft_memset(inst_arr, 0, BUFFER_SIZE);
		// inst_arr_idx is index!! size is inst_arr_idx + 1!!!!!!!!1
		int	inst_arr_idx = -1;
		while ((read(0, &c, sizeof(c)) > 0) && (c != '\n'))
		{
			if (c <= KEY_LEFT_ARROW)
				inst_arr[++inst_arr_idx] = c;
			get_cursor_pos(&tc.cursor.col, &tc.cursor.row);
			if (ft_isprint(c))
				ft_putchar_fd(c, 1);
			else if (c == KEY_LEFT_ARROW)
				ft_cursor_mv_left(tc.cursor.col, prompt.size);
			else if (c == KEY_RIGHT_ARROW)
				ft_cursor_mv_right(tc.cursor.col, prompt.size + buf_len);
			else if (c == KEY_UP_ARROW)
				inst_arr_idx = handle_up_arrow(tc, inst_arr, inst_arr_idx) - 1;
			else if (c == KEY_BACKSPACE)
				ft_cursor_clr_line_end(tc.tc_str, tc.cursor.col, prompt.size);
			c = 0;
		}
		ret = get_str_by_inst_arr(inst_arr, inst_arr_idx + 1);
	}
	return (0);	
}
