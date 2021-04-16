/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:21:18 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:21:21 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	sh_bti_pwd(char **args)
{
	char s[BUFFER_SIZE];

	if (*args)
	{
		printf("%s\n", "pwd: too many arguments");
		return (1);
	}
	getcwd(s, BUFFER_SIZE);
	printf("%s\n", s);
	return 0;
}
