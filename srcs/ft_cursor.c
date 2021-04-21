/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:16:10 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 15:21:14 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	ft_cursor_mv_col(t_tc *tc)
{
	char	*str;

	tputs(tgoto(tc->tc_str[TC_CM], tc->cursor.col - 1, \
				tc->cursor.row - 1), 1, ft_putchar_tc);
	return (0);
}

int
	ft_cursor_mv_head(t_tc *tc)
{
	char	*str;

	tputs(tgoto(tc->tc_str[TC_CM], 0, \
				tc->cursor.row - 1), 1, ft_putchar_tc);
	return (0);
}

int
	ft_cursor_clr_line_all(t_tc *tc)
{
	tputs(tc->tc_str[TC_DL], 1, ft_putchar_tc);
	ft_cursor_mv_head(tc);
	return (0);
}

int
	ft_cursor_clr_line_end(
	t_tc *tc,
	int left_limit)
{
	if (tc->cursor.col > left_limit + 1)
	{
		ft_putchar_fd('\b', STDOUT_FILENO);
		tputs(tc->tc_str[TC_CE], 1, ft_putchar_tc);
	}
	return (0);
}

void
	get_cursor_pos(int *col, int *row)
{
	int		cnt;
	int		idx;
	char	buf[255];
	int		read_size;

	write(STDIN_FILENO, "\033[6n", ft_strlen("\033[6n"));
	read_size = read(STDIN_FILENO, buf, 255);
	buf[read_size] = '\0';
	idx = -1;
	while (!ft_isdigit(buf[idx]))
		++idx;
	*row = 0;
	while (ft_isdigit(buf[idx]))
		*row = *row * 10 + buf[idx++] - '0';
	++idx;
	*col = 0;
	while (ft_isdigit(buf[idx]))
		*col = *col * 10 + buf[idx++] - '0';
}
