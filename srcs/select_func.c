#include "../incs/minishell.h"

static char	*get_builtin_path(char *cand, char *cmd)
{
	DIR				*dir_name;
	struct dirent	*item;
	char			*ret;

	ret = NULL;
	dir_name = opendir(cand);
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
#if 0
int select_func(t_list *arg_list, char *path)
{
	int		ret;
	int		idx;
	char	*cmd;
	char	*builtin_path;
	char	**cand_arr;

	ret = 0;
	if (trim_cmd(arg_list))
	{
		printf("ERROR: trim_cmd malloc error\n");	
		return (1);
	}
	cmd = arg_list->data;
	//divide path (:)
	cand_arr = pk_split(path, path, ':', INF);
	idx = -1;
	// you cannot find builtin_path, It has NULL value
	builtin_path = NULL;
	while (cand_arr[++idx])
	{
		if ((builtin_path = get_builtin_path(cand_arr[idx], cmd)))
			break ;
	}
	printf("builtin_path: %s\n", builtin_path);
	//if(builtin_path) -> fork
	//else builtin_path is NULL -> show error message.
	//after using builtin function with execve, free path.
	//arg_beg = arg_list->next;
	//make list to arr function.(arg_beg, env_list)
	//execve(path, arg_beg, env)
	//after using arg_beg array, env array, free.(pk_split_free)
	//strncmp(find one)
	return (ret);
}
#endif

int select_func(t_set *set, char *path, t_list *env_list)
{
	int		ret;
	int		idx;
	char	**env_arr;
	char	*builtin_path;
	char	**cand_arr;

	ret = 0;
	if (!(set->cmd = trim_cmd(set->cmd)))
	{
		printf("ERROR: trim_cmd malloc error\n");	
		return (1);
	}
	//divide path (:)
	cand_arr = pk_split(path, path, ':', INF);
	idx = -1;
	builtin_path = NULL;
	while (cand_arr[++idx])
	{
		if ((builtin_path = get_builtin_path(cand_arr[idx], set->cmd)))
			break ;
	}
	printf("builtin_path: %s\n", builtin_path);
	env_arr = cvt_list_to_arr(env_list);
	printf("Display Env_arr===========================\n");
	//print_darr(env_arr);
	free_darr(env_arr, INF);
	execve(path, set->args, env_arr);

	//if(builtin_path) -> fork
	//else builtin_path is NULL -> show error message.
	//after using builtin function with execve, free path.
	//arg_beg = arg_list->next;
	//make list to arr function.(arg_beg, env_list)
	//after using arg_beg array, env array, free.(pk_split_free)
	//strncmp(find one)
	return (ret);
}
