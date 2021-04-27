/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo_sh_bti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:12 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:49:08 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	redo_sh_bti(t_info *info, t_tokens *tokens, t_tokens *prev)
{
	char	*cmd;
	char	**args;
	int		ret;
	int		prev_type;

	ret = 1;
	cmd = tokens->cmd;
	args = tokens->args;
	prev_type = 0;
	if (prev != NULL)
		prev_type = prev->type & TYPE_PIPE;
	if (!exact_strncmp(cmd, "export"))
		ret = sh_bti_export(args, &(info->env_list), FLAG_PRINT_ON);
	else if (!exact_strncmp(cmd, "unset"))
		ret = sh_bti_unset(args, &(info->env_list), FLAG_PRINT_ON);
	else if (!exact_strncmp(cmd, "cd"))
		ret = sh_bti_cd(args, info->env_list, FLAG_PRINT_ON);
	else if (!exact_strncmp(cmd, "exit") &&
			(prev_type != TYPE_PIPE))
		ret = sh_bti_exit(args, info, FLAG_PRINT_ON);
	else
		ret = 0;
	return (ret);
}
