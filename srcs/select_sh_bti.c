/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sh_bti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:31 by juepark           #+#    #+#             */
/*   Updated: 2021/04/26 18:38:30 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	select_sh_bti(t_tokens *tokens, t_info *info)
{
	char	**args;
	int		ret;

	ret = ERR_NOT_FOUND;
	args = tokens->args;
	if (!exact_strncmp(tokens->cmd, "export"))
		ret = sh_bti_export(args, &(info->env_list), FLAG_PRINT_OFF);
	else if (!exact_strncmp(tokens->cmd, "unset"))
		ret = sh_bti_unset(args, &(info->env_list), FLAG_PRINT_OFF);
	else if (!exact_strncmp(tokens->cmd, "env"))
		ret = sh_bti_env(info->env_list);
	else if (!exact_strncmp(tokens->cmd, "cd"))
		ret = sh_bti_cd(args, info->env_list, FLAG_PRINT_OFF);
	else if (!exact_strncmp(tokens->cmd, "pwd"))
		ret = sh_bti_pwd(args);
	else if (!exact_strncmp(tokens->cmd, "echo"))
		ret = sh_bti_echo(args, info->env_list);
	else if (!exact_strncmp(tokens->cmd, "exit"))
		ret = sh_bti_exit(args, info, FLAG_PRINT_OFF);
	if (ret == 1)
		return (ERR_SH_BTI);
	return (ret);
}
