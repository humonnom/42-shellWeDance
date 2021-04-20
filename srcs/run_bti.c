/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */ /*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:23 by juepark           #+#    #+#             */
/*   Updated: 2021/04/16 13:20:24 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*get_bti_path_from_cmd(char *cmd)
{
	char	*ret;
	int		size;
	char	*tmp;

	tmp = ft_strrchr(cmd, '/');
	size = tmp - cmd;
	ret = ft_substr(cmd, 0, size);
	return (ret);
}

char	*get_cmd_without_path(char *cmd)
{
	char	*ret;
	int		beg_idx;
	char	*tmp;

	tmp = ft_strrchr(cmd, '/');
	beg_idx = ft_strlen(cmd) - ft_strlen(tmp) + 1;
	ret = ft_substr(cmd, beg_idx, INF);
	return (ret);
}

char	*get_bti_path_from_env_path(char *cand, char *cmd)
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

int
	run_bti_with_path(
	t_tokens *tokens,
	t_list *env_list,
	char **env_arr)
{
	char	*bti_path;
	char	*bti_dir_path;
	char	*pure_cmd;

	bti_path = handle_arg(tokens->cmd, env_list);
	free(tokens->cmd);
	tokens->cmd = bti_path;
	bti_dir_path = get_bti_path_from_cmd(bti_path);
	if (is_exist_dir(bti_dir_path))
	{
		pure_cmd = get_cmd_without_path(tokens->cmd);
		tokens->tokens[0] = pure_cmd;
		if(execve(bti_path, tokens->tokens, env_arr))
			free(bti_dir_path);
		free(pure_cmd);
		tokens->tokens[0] = tokens->cmd;
		return (1);
	}
	free(bti_dir_path);
	return (0);
}

int			run_bti(t_tokens *tokens, t_list *env_list)
{
	char	*func_path;
	char	**cand_arr;
	int		idx;
	char	*bti_path;
	char	**env_arr;

	env_arr = set_list_to_darr(env_list);
	if (run_bti_with_path(tokens, env_list, env_arr))
		return (BTI_ERR);
	if (!(func_path = get_eval(env_list, "PATH")))
		return (BTI_ERR);
	cand_arr = pk_split(func_path, func_path, ':', INF);
	idx = -1;
	bti_path = NULL;
	while (cand_arr[++idx])
	{
		if ((bti_path = get_bti_path_from_env_path(cand_arr[idx], tokens->cmd)))
			break ;
	}
	free_darr(cand_arr, INF);
	if (!bti_path || execve(bti_path, tokens->tokens, env_arr) < 0)
		return (BTI_ERR);
	free(bti_path);
	free_darr(env_arr, INF);
	return (0);
}
