#include "../incs/minishell.h"

static int is_valid_filename(char *filename, int curr_type)
{
	char	s[PATH_MAX];
	char	*cwd;
	char	*path;
	int		ret;

	ret = 0;
	if (filename == NULL)
		printf("zsh: parse error near `\n'");
	else if (curr_type & TYPE_REIN)
	{
		cwd = getcwd(s, PATH_MAX);
		path = get_bti_path(cwd, filename);
		if (!path)
			printf("zsh: no such file or directory: %s\n", filename);
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

static int	seek_filename(
			char *str,
			char **filename)
{
	int idx;
	int ret;
	int beg;
	int end;

	idx = 0;
	while (str[idx] && str[idx] == ' ')
		idx++;
	beg = idx;
	while (str[idx] && str[idx] != ' ' && !is_bracket(str[idx]))
		idx++;
	end = idx;
	*filename = ft_substr(str, beg, end - beg);
	if (!filename)
		return (0);
	return (end);
}

static int	set_fd_info_part(t_set *set, char *filename)
{
	int	fd;


	if (set->type & TYPE_REIN)
		fd = open(filename, O_RDONLY);
	if (set->type & TYPE_REOUT)
		fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0755);
	if (set->type & TYPE_REOUT_D)
		fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0755);
	if (fd < 0)
		return (0);
	if (set->type & TYPE_REIN)
		set->fd_in[set->fd_in_idx++] = fd;
	if (set->type & (TYPE_REOUT | TYPE_REOUT_D))
		set->fd_out[set->fd_out_idx++] = fd;
	return (1);
}

int			set_fd_info(t_set *set, char *str, int curr_type)
{
	int		ret;
	int		idx_inc;
	char	*filename;

	filename = NULL;
	idx_inc = seek_filename(str, &filename);
	if (idx_inc == 0)
		return (0);
	ret = is_valid_filename(filename, curr_type);
	if (ret)
		ret = set_fd_info_part(set, filename);
	if (ret)
		ret = idx_inc;
	free(filename);
	return (ret);
}
