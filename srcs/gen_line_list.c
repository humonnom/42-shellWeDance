/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_line_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:16:56 by juepark           #+#    #+#             */
/*   Updated: 2021/04/26 20:42:19 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int	g_signal;

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

static int
	handle_single_semi_colon(char *line)
{
	if (line[0] == ';' && line[1] == '\0')
	{
		ft_putstr_fd("syntax error near unexpected token `;\'\n",\
		STDOUT_FILENO);
		g_signal = 258;
		return (1);
	}
	return (0);
}

static int
	handle_double_semi_colon(char *line)
{
	if (ft_strnstr(line, ";;", INF))
	{
		ft_putstr_fd("syntax error near unexpected token `;;\'\n",\
		STDOUT_FILENO);
		g_signal = 258;
		return (1);
	}
	return (0);
}

t_list
	*gen_line_list(char *line)
{
	char	*line_cpy;
	char	**line_arr;
	t_list	*ret;

	ret = NULL;
	if (handle_single_semi_colon(line))
		return (NULL);
	if (!(line_cpy = ft_strdup(line)))
		return (NULL);
	if (handle_quote(line, &line_cpy, ';'))
	{
		printf("ERROR: INVALID QUOTE PAIR\n");
		return (NULL);
	}
	if (handle_double_semi_colon(line_cpy))
		return (NULL);
	line_arr = pk_split(line, line_cpy, ';', INF);
	free(line_cpy);
	if (is_valid_line_arr(line_arr))
		return (handle_invalid_line_arr(line_arr));
	if (set_darr_to_list(&ret, line_arr))
		return (NULL);
	free_darr(line_arr, INF);
	return (ret);
}
