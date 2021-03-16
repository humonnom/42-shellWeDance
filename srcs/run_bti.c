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
		if (!ft_strncmp(item->d_name, cmd, ft_strlen(item->d_name)))
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

static	int	control_process(
			char *bti_path,
			char **set_arr,
			char **env_arr)
{
	pid_t	pid;

	pid = fork();
	handle_sig_proc(pid);
	if (pid == 0)
	{
		//printf("This is Child. PID: %d\n", pid);
		execve(bti_path, set_arr, env_arr);
	}
	else if (pid > 0)
	{
		//printf("This is Parents. PID: %d\n", pid);
		wait((int *) 0);
	}
	else
		return (1);
	return (0);
}

int			run_bti(t_info *info)
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
	//printf("bti_path: %s\n", bti_path);
	if (control_process(bti_path, info->set->set, env_arr))
		return (1);
	free_darr(env_arr, INF);
	free_darr(cand_arr, INF);
	return (0);
}
