/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:08 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:20:09 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	print_tokens(t_tokens *tokens)
{
	int	idx;

	printf("cmd: %s\n", tokens->cmd);
	idx = -1;
	while (tokens->args[++idx])
	{
		printf("arg[%d]: %s\n", idx, tokens->args[idx]);
	}
	printf("type: %d\n", tokens->type);
}
