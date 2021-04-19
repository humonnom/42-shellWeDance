/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_line_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:16:56 by juepark           #+#    #+#             */
/*   Updated: 2021/04/20 00:49:50 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

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

t_list	*gen_line_list(char *line_tmp)
{
	char	*line;
	char	*line_cpy;
	char	**line_arr;
	t_list	*ret;

	ret = NULL;
	if (!(line = handle_back_slash(line_tmp, '\\')))
		return (NULL);
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
	free(line);
	return (ret);
}
