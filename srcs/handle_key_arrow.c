/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_arrow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:43 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:45:27 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static int
	join_history_line(
	t_info *info,
	long inst_arr[],
	long key_arrow,
	int left_limit)
{
	int		ret;
	char	*history_line;

	ft_cursor_clr_line_end_loop(info, left_limit);
	ft_memset(inst_arr, 0, BUFFER_SIZE);
	if (key_arrow == KEY_UP_ARROW && info->history_ptr->next != NULL)
		info->history_ptr = info->history_ptr->next;
	if (key_arrow == KEY_DOWN_ARROW && info->history_ptr->prev != NULL)
		info->history_ptr = info->history_ptr->prev;
	history_line = (char *)(info->history_ptr->data);
	ft_putstr_fd(PROMPT_DATA, STDOUT_FILENO);
	ft_putstr_fd(history_line, STDOUT_FILENO);
	ret = -1;
	while (++ret < (int)ft_strlen(history_line))
		inst_arr[ret] = (long)history_line[ret];
	return (ret);
}

static int
	ft_cursor_mv_left(
	int col,
	int left_limit,
	long *arr)
{
	char	*str;

	str = "\033[D";
	if (col > left_limit + 1)
		write(STDIN_FILENO, str, ft_strlen(str));
	ft_memset(arr, 0, BUFFER_SIZE);
	return (0);
}

static int
	ft_cursor_mv_right(
	int col,
	int right_limit,
	long *arr)
{
	char	*str;

	str = "\033[C";
	if (col <= right_limit)
		write(STDIN_FILENO, str, ft_strlen(str));
	ft_memset(arr, 0, BUFFER_SIZE);
	return (0);
}

int
	handle_key_arrow(
	t_info *info,
	long arr[],
	long c,
	int right_limit)
{
	int		left_limit;
	int		ret;

	if (info->history_ptr == NULL)
		return (0);
	ret = 0;
	if (c == KEY_LEFT_ARROW)
		ft_cursor_mv_left(info->tc.cursor.col, PROMPT_SIZE, arr);
	else if (c == KEY_RIGHT_ARROW)
		ft_cursor_mv_right(info->tc.cursor.col, right_limit, arr);
	left_limit = info->tc.limit - PROMPT_SIZE;
	if (c == KEY_UP_ARROW || c == KEY_DOWN_ARROW)
		ret = join_history_line(info, arr, c, left_limit) - 1;
	return (ret);
}
