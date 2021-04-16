/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tokens_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:04 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:17:05 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

t_list	*gen_tokens_list_part(t_info *info, char **str)
{
	int			idx;
	t_tokens	*tmp_tokens;
	t_list		*ret;

	ret = NULL;
	idx = -1;
	while (str[++idx])
	{
		tmp_tokens = gen_tokens(info, str[idx]);
		if (tmp_tokens == NULL)
		{
			ft_lstclear(&ret, &free_tokens);
			return (NULL);
		}
		else
		{
			if (str[idx + 1] == NULL)
				tmp_tokens->type |= TYPE_BREAK;
			else
				tmp_tokens->type |= TYPE_PIPE;
			ft_lstadd_back(&ret, ft_lstnew(tmp_tokens));
		}
	}
	return (ret);
}

t_list	*gen_tokens_list(t_info *info)
{
	char	*line;
	char	*line_cpy;
	char	**line_part;
	t_list	*ret;
	int		error_num;

	line = info->line_list->data;
	ret = NULL;
	error_num = 0;
	if (!(line_cpy = ft_strdup(line)))
		return (NULL);
	if (handle_quote(line, &line_cpy, '|'))
		error_num = turn_on_bit(error_num, 0);
	if (!(line_part = pk_split(line, line_cpy, '|', INF)))
		error_num = turn_on_bit(error_num, 1);
	ret = gen_tokens_list_part(info, line_part);	
	free (line_cpy);
	if (!check_bit(error_num, 1))
		free_darr(line_part, INF);
	if (error_num)
		return (NULL);
	return (ret);
}
