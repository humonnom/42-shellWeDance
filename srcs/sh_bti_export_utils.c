/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_export_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:40:56 by yekim             #+#    #+#             */
/*   Updated: 2021/04/26 18:36:20 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

#define ERR_EXPORT_EMPTY_KEY 4
#define ERR_EXPORT_NUM_KEY 3

extern int g_signal;

int
	is_invalid_key(t_env *env, int flag_print, char *cmd_type)
{
	if (env->key[0] == '\0')
	{
		g_signal = 1;
		if (flag_print)
			printf("%s: not an identifier: `=%s'\n", cmd_type, env->val);
		return (ERR_EXPORT_EMPTY_KEY);
	}
	if (env->key[0] == '=')
	{
		g_signal = 1;
		if (flag_print)
			printf("%s: not an identifier: `=%s'\n", cmd_type, env->val);
		return (ERR_EXPORT_EMPTY_KEY);
	}
	return (0);
}

int
	is_digit_in_key_head(t_env *env, int flag_print, char *cmd_type)
{
	if (ft_isdigit((env->key)[0]))
	{
		g_signal = 1;
		if (flag_print)
			printf("%s: not an identifier: `%s'\n", cmd_type, env->key);
		return (ERR_EXPORT_NUM_KEY);
	}
	return (0);
}

int
	is_equal_in_str(char *str)
{
	int	ret;

	ret = 0;
	if (ft_strchr(str, '='))
		ret = 1;
	return (ret);
}

int
	is_empty_str(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '\0')
		return (1);
	return (0);
}
