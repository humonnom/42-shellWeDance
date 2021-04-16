#include "../incs/minishell.h"

int		is_exist_dir(char *dir_path)
{
	DIR				*dir_name;
	struct dirent	*item;

	if(!(dir_name = opendir(dir_path)))
		return (0);
	closedir(dir_name);
	return (1);
}

