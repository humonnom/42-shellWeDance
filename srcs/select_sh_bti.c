/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sh_bti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:31 by juepark           #+#    #+#             */
/*   Updated: 2021/04/21 20:50:40 by jackjoo          ###   ########.fr       */
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
		ret = sh_bti_export(args, &(info->env_list), FLAG_EXPORT_PRINT_OFF);
	if (!exact_strncmp(tokens->cmd, "unset"))
		ret = sh_bti_unset(args, &(info->env_list));
	if (!exact_strncmp(tokens->cmd, "env"))
		ret = sh_bti_env(info->env_list);
	if (!exact_strncmp(tokens->cmd, "cd"))
		ret = sh_bti_cd(args, info->env_list);
	if (!exact_strncmp(tokens->cmd, "pwd"))
		ret = sh_bti_pwd(args);
	if (!exact_strncmp(tokens->cmd, "echo"))
		ret = sh_bti_echo(args, info->env_list);
	if (!exact_strncmp(tokens->cmd, "unset"))
		ret = sh_bti_echo(args, info->env_list);
	if (!exact_strncmp(tokens->cmd, "exit"))
		sh_bti_exit(args, info);
	if (ret == 1)
		return (ERR_SH_BTI);
	return (ret);
}
