/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_oldpwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:18:21 by juepark           #+#    #+#             */
/*   Updated: 2021/04/17 21:40:25 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	init_oldpwd(t_list **env_head)
{
	t_list	*tmp_elist;
	t_env	*tmp_env;
	char	*new_val;

	if (!(tmp_elist = get_elist(*env_head, "OLDPWD")))
		return (1);
	tmp_env = (t_env *)(tmp_elist->data);
	new_val = ft_strdup("");
	if (mod_eval(tmp_env, new_val))
		return (1);
	free(new_val);
	new_val = NULL;
	return (0);
}
