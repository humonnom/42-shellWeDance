/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:18 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 21:19:03 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int g_signal;

int	sh_bti_pwd(char **args)
{
	char s[BUFFER_SIZE];

	getcwd(s, BUFFER_SIZE);
	printf("%s\n", s);
	g_signal = 0;
	return (0);
}
