#include "../incs/minishell.h"

static char	*get_bti_path(char *cand, char *cmd)
{
	DIR				*dir_name;
	struct dirent	*item;
	char			*ret;

	ret = NULL;
	if(!(dir_name = opendir(cand)))
		return (NULL);
	while ((item = readdir(dir_name)))
	{
		if (!ft_strncmp(item->d_name, cmd, ft_strlen(item->d_name)))
		{
			ret = ft_strjoin(cand, "/");
			ret = ft_strjoin(ret, item->d_name); 
			return (ret);
		}
	}
	closedir(dir_name);
	return (ret);
}

int	run_bti(t_info *info)
{
	char	*func_path;
	char	**cand_arr;
	int		idx;
	char	*bti_path;
	char	**env_arr;

	if (!(func_path = get_eval(info->env_list, "PATH")))
		printf("ERROR: func_path is NULL\n");
	cand_arr = pk_split(func_path, func_path, ':', INF);
	idx = -1;
	bti_path = NULL;
	while (cand_arr[++idx])
	{
		if ((bti_path = get_bti_path(cand_arr[idx], info->set->cmd)))
			break ;
	}
	env_arr = cvt_list_to_arr(info->env_list);
	execve(bti_path, info->set->set, env_arr);
	free_darr(env_arr, INF);
	free_darr(cand_arr, INF);
	return (0);
}
