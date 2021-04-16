/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_darr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:15:47 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:15:48 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	**free_darr(char **tab, int limit)
{
	int	idx;

	idx = -1;
	while (tab[++idx] && limit--)
		free(tab[idx]);
	free(tab);
	tab = NULL;
	return (0);
}
