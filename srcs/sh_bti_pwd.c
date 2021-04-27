/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:18 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:53:39 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

int	sh_bti_pwd(void)
{
	char s[BUFFER_SIZE];

	getcwd(s, BUFFER_SIZE);
	ft_putstr_fd(s, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	g_signal = 0;
	return (0);
}
