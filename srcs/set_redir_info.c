#include "../incs/minishell.h"

static int is_valid_filename(char *filename, int type)
{
	char	s[PATH_MAX];
	char	*cwd;
	char	*path;
	int		tmp_type;
	int		ret;

	ret = 0;
	if (filename == NULL)
		printf("zsh: parse error near `\n'");
	else if (type == TYPE_REIN)
	{
		cwd = getcwd(s, PATH_MAX);
		path = get_bti_path(cwd, filename);
		if (!path)
			printf("zsh: no such file or directory: %s\n", filename);
		else
			free(path);
	}
	else
		ret = 1;
	return (ret);
}

static int	seek_filename(
			char	*str,
			char	**filename,
			int		type)
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
		return (-1);
	return (end);
}

static int	set_fd_info(t_info *info, char *filename, int type)
{
	int	fd;

	if (type == TYPE_REIN)
		fd = open(filename, O_RDONLY);
	if (type == TYPE_REOUT)
		fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0755);
	if (type == TYPE_REOUT_D)
		fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0755);
	if (fd < 0)
		return (1);
	if (type == TYPE_REIN)
		info->fd_in[info->fd_in_idx++] = fd;
	if (type == TYPE_REOUT || type == TYPE_REOUT_D)
		info->fd_out[info->fd_out_idx++] = fd;
	return (0);
}

int			set_redir_info(t_info *info, char *str, int type)
{
	int		ret;
	int		idx_inc;
	char	*filename;

	filename = NULL;
	idx_inc = seek_filename(str, &filename, type);
	if (!(idx_inc > 0))
		return (-1);
	ret = idx_inc;
	if (!is_valid_filename(filename, type))
		ret = -1;
	if (ret != -1 && set_fd_info(info, filename, type))
		ret = -1;
	free(filename);
	return (ret);
}
