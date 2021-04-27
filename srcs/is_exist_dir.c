/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:32:17 by yekim             #+#    #+#             */
/*   Updated: 2021/04/27 14:48:59 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int
	is_exist_dir(char *dir_path)
{
	DIR				*dir_name;

	if (!(dir_name = opendir(dir_path)))
		return (0);
	closedir(dir_name);
	return (1);
}
