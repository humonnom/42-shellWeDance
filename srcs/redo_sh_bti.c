/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo_sh_bti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:12 by juepark           #+#    #+#             */
/*   Updated: 2021/04/18 22:54:47 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	redo_sh_bti(t_tokens *tokens, t_info *info)
{
	char	*cmd;
	char	**args;
	int		ret;
	int		cmp_len;
	
	ret = 1;
	cmd = tokens->cmd;
	args = tokens->args;
	if (!exact_strncmp(cmd, "export") && args[0] != NULL)
		ret = sh_bti_export(args, &(info->env_list));
	else if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_unset(args, &(info->env_list));
	else if (!exact_strncmp(cmd, "cd"))
		ret = sh_bti_cd(args, info->env_list);
	else if (!exact_strncmp(cmd, "exit"))
		sh_bti_exit(info);
	else
		ret = 0;
	return (ret);
}
