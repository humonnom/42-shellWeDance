/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bti_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:17:08 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:17:09 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*get_bti_path(char *cand, char *cmd)
{
	DIR				*dir_name;
	struct dirent	*item;
	char			*ret;
	char			*tmp;

	ret = NULL;
	if(!(dir_name = opendir(cand)))
		return (NULL);
	while ((item = readdir(dir_name)))
	{
		if (!exact_strncmp(item->d_name, cmd))
		{
			ret = ft_strjoin(cand, "/");
			tmp = ret;
			ret = ft_strjoin(ret, item->d_name); 
			free(tmp);
			return (ret);
		}
	}
	closedir(dir_name);
	return (ret);
}
