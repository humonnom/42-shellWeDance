/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:16:04 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:44:28 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	free_tokens(void *tokens_tmp)
{
	t_tokens	*tokens;

	tokens = (t_tokens *)tokens_tmp;
	free_darr(tokens->tokens, INF);
	free(tokens->cmd);
	tokens->cmd = NULL;
	free(tokens);
	tokens = NULL;
}
