/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_tc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:30:05 by yekim             #+#    #+#             */
/*   Updated: 2021/04/27 14:59:25 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int	g_signal;

static char
	*get_str_by_inst_arr(long inst_arr[], int inst_arr_size)
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
		if (inst_arr[idx] == KEY_BACKSPACE_KEY)
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

static int
	handle_read_data(t_info *info, long *c, long *arr, int *buf_len)
{
	int	ret;

	ret = 0;
	if (ft_isprint(*c))
	{
		*buf_len = *buf_len + 1;
		ft_putchar_fd(*c, STDOUT_FILENO);
	}
	else if (is_key_arrow(*c))
		ret = handle_key_arrow(info, arr, *c, info->tc.limit + *buf_len);
	else if (*c == KEY_BACKSPACE_KEY)
	{
		*buf_len = calc_max(*buf_len - 1, 0);
		ft_cursor_clr_line_end(&(info->tc), info->tc.limit);
	}
	*c = 0;
	return (ret);
}

static void
	turn_off_tc_setting(t_info *info)
{
	info->tc.term.c_lflag &= ~ECHO;
	info->tc.term.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &(info->tc.term));
}

static int
	set_inst_arr_in_loop(
	t_info *info,
	long *arr)
{
	long	c;
	int		buf_len;
	int		idx;
	int		tmp;

	buf_len = 0;
	idx = -1;
	c = 0;
	while ((read(STDIN_FILENO, &c, sizeof(c))) > 0 && (c != '\n'))
	{
		if (c == KEY_EOF)
			handle_eof_in_gnl(info, &c, buf_len);
		handle_sig_in_gnl(info, arr, &idx, &buf_len);
		get_cursor_pos(&(info->tc.cursor.col), &(info->tc.cursor.row));
		if (c != '\t' && c <= 4500000)
			arr[++idx] = c;
		tmp = handle_read_data(info, &c, arr, &buf_len);
		if (tmp)
			idx = tmp;
	}
	if (c == '\n')
		ft_putstr_fd("\n", STDOUT_FILENO);
	if (g_signal)
		handle_sig_in_gnl(info, arr, &idx, &buf_len);
	return (idx + 1);
}

char
	*get_next_line_tc(t_info *info)
{
	char	*ret;
	long	inst_arr[BUFFER_SIZE];
	int		inst_arr_size;

	ret = NULL;
	turn_off_tc_setting(info);
	get_cursor_pos(&(info->tc.cursor.col), &(info->tc.cursor.row));
	ft_cursor_mv_head(&(info->tc), 1);
	info->tc.limit = info->tc.cursor.col - 1 + PROMPT_SIZE;
	ft_putstr_fd(PROMPT_DATA, STDOUT_FILENO);
	ft_memset(inst_arr, 0, BUFFER_SIZE);
	inst_arr_size = set_inst_arr_in_loop(info, inst_arr);
	if (inst_arr[0] != 0)
		ret = get_str_by_inst_arr(inst_arr, inst_arr_size);
	return (ret);
}
