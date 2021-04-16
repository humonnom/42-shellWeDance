/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:00 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 21:18:50 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

static int	is_n_flag(char *str)
{
	int ret;
	int idx;

	ret = 0;
	idx = 0;
	if (str[idx] == '-')
		ret = 1;
	while (ret == 1 && str[++idx])
	{
		if (str[idx] != 'n')
			ret = 0;
	}
	return (ret);
}

int			sh_bti_echo(char **args, t_list *env_list)
{
	int		idx;
	int		n_flag;
	char	*tmp;

	n_flag = 0;
	idx = -1;
	while (args[++idx] && is_n_flag(args[idx]))
		n_flag = 1;
	idx--;
	while (args[++idx])
	{
		tmp = handle_arg(args[idx], env_list);
		write(STDOUT_FILENO, tmp, ft_strlen(tmp));
		if (args[idx + 1] != 0)
			write(1, " ", 1);
		free(tmp);
	}
	if (!n_flag)
		write(1, "\n", 1);
	g_signal = 0;
	return (0);
}
