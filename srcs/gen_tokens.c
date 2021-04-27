/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:00 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:41:54 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

char
	**set_del_quote_args(char **args)
{
	int	idx;

	idx = -1;
	while (args[++idx])
		del_quote(&args[idx]);
	return (args);
}

void
	trim_tokens(t_tokens *ret, char **tmp_tokens)
{
	ret->tokens = tmp_tokens;
	ret->cmd = ft_strdup(tmp_tokens[0]);
	if (del_quote(&(ret->cmd)))
	{
		printf("ERROR: trim_cmd malloc error\n");
		g_signal = 1;
		ret = NULL;
		return ;
	}
	if (exact_strncmp(ret->cmd, "export"))
		ret->args = set_del_quote_args(&tmp_tokens[1]);
	else
		ret->args = &tmp_tokens[1];
}

t_tokens
	*gen_tokens(char *line)
{
	char		*set_fd_res;
	char		*set_fd_res_cpy;
	char		**tmp_tokens;
	t_tokens	*ret;

	if (!(ret = (t_tokens *)malloc(sizeof(t_tokens))))
		return (NULL);
	set_fd_res = set_fd(ret, line);
	if (set_fd_res == NULL)
		return (NULL);
	set_fd_res_cpy = ft_strdup(set_fd_res);
	handle_quote(line, &set_fd_res_cpy, ' ');
	if (!(tmp_tokens = pk_split(set_fd_res, set_fd_res_cpy, ' ', INF)))
		return (NULL);
	trim_tokens(ret, tmp_tokens);
	free(set_fd_res);
	free(set_fd_res_cpy);
	return (ret);
}
