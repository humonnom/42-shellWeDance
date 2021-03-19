#include "../incs/minishell.h"

static char	*get_bti_path(char *cand, char *cmd)
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

int			run_bti(t_set *set, t_list *env_list)
{
	char	*func_path;
	char	**cand_arr;
	int		idx;
	char	*bti_path;
	char	**env_arr;

	if (!(func_path = get_eval(env_list, "PATH")))
		printf("ERROR: func_path is NULL\n");
	cand_arr = pk_split(func_path, func_path, ':', INF);
	idx = -1;
	bti_path = NULL;
	while (cand_arr[++idx])
	{
		if ((bti_path = get_bti_path(cand_arr[idx], set->cmd)))
			break ;
	}
	env_arr = set_list_to_darr(env_list);
	printf("bti_path: %s\n", bti_path);
	if (execve(bti_path, set->set, env_arr) < 0)
		return (1);
	free_darr(env_arr, INF);
	free_darr(cand_arr, INF);
	return (0);
}
