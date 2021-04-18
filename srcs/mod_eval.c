/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_eval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:18:50 by juepark           #+#    #+#             */
/*   Updated: 2021/04/18 22:19:24 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	mod_eval(t_env *env, char *new_val)
{
	free(env->val);
	env->val = NULL;
	if (!(env->val = ft_strdup(new_val)))
		return (1);
	return (0);
}
