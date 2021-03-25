#include "../incs/minishell.h"

static int is_valid_file_name(char *file_name, int type)
{
	char	s[PATH_MAX];
	char	*cwd;
	char	*path;
	int		ret;

	ret = 0;
	if (file_name == NULL)
		printf("zsh: parse error near `\n'");
	else if (type & TYPE_REIN)
	{
		cwd = getcwd(s, PATH_MAX);
		path = get_bti_path(cwd, file_name);
		if (!path)
			printf("zsh: no such file or directory: %s\n", file_name);
		else
		{
			free(path);
			ret = 1;
		}
	}
	else
		ret = 1;
	return (ret);
}

static char	*get_file_name(
			char *str,
			int *inc_idx)
{
	int		beg;
	int		end;
	char	*ret;

	while (str[*inc_idx] && str[*inc_idx] == ' ')
		++(*inc_idx);
	beg = *inc_idx;
	while (str[*inc_idx] && str[*inc_idx] != ' '
			&& !is_bracket(str[*inc_idx]))
		++(*inc_idx);
	end = *inc_idx;
	ret = ft_substr(str, beg, end - beg);
	if (!ret)
		return (NULL);
	return (ret);
}

int			is_valid_fd(
			t_set *set,
			char *str,
			int *idx,
			int type)
{
	int		ret;
	char	*file_name;
	int		inc_idx;

	ret = 0;
	inc_idx = 0;
	file_name = get_file_name(str, &inc_idx);
	printf("is_valid_fd::file_name: %s\n", file_name);
	if (!file_name)
		return (0);
	ret = is_valid_file_name(file_name, type);
	free(file_name);
	*idx += inc_idx;
	return (ret);
}
