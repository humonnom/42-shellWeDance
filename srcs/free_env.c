/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:15:59 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:42:14 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	free_env(void *env_tmp)
{
	t_env *env;

	env = (t_env *)env_tmp;
	free(env->key);
	env->key = NULL;
	free(env->val);
	env->val = NULL;
	free(env);
	env = NULL;
}
