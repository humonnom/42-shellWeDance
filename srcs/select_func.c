#include "../incs/minishell.h"

static char	*get_builtin_path(char *cand, char *cmd)
{
	DIR				*dir_name;
	struct dirent	*item;
	char			*path;

	path = NULL;
	dir_name = opendir(cand);
	while ((item = readdir(dir_name)))
	{
		if (ft_strncmp(item->d_name, cmd, ft_strlen(cmd)) == 0)
			path = ft_strjoin(cand, item->d_name); 
		printf("item->d_mane: %s\n", item->d_name);
	}
	closedir(dir_name);
	return (path);
}

int select_func(t_list *arg_list, char *path)
{
	int		ret;
	int		idx;
	char	*cmd;
	char	*builtin_path;
	char	**cand_arr;

	ret = 0;
	if (trim_cmd(arg_list))
		return (1);
	cmd = arg_list->data;
	//devide path (:)
	cand_arr = pk_split(path, path, ':', INF);
	idx = -1;
	builtin_path = NULL;
	while (cand_arr[++idx])
		builtin_path = get_builtin_path(cand_arr[idx], cmd);
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
