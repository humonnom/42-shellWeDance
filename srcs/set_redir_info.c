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
	else if ((tmp_type = is_bracket(filename[0], filename[1])))
	{
		printf("zsh: parse error near `%c", filename[0]);
		if (tmp_type == TYPE_REOUT_D)
			printf("%c", filename[1]);
		printf("'\n");
	}
	else if (type == TYPE_REIN)
	{
		cwd = getcwd(s, PATH_MAX);
		path = get_bti_path(cwd, filename);
		if (!path)
			printf("zsh: no such file or directory: %s\n", filename);
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

	idx = 1;
	if (type == TYPE_REOUT_D)
		idx++;
	while (str[idx] && str[idx] == ' ')
		idx++;
	beg = idx;
	while (str[idx] && str[idx] != ' ')
		idx++;
	end = idx;
	*filename = ft_substr(str, beg, end - beg);
	if (!filename)
		return (-1);
	printf("filename: %s\n", *filename);
	return (end);
}

static int	set_fd_info(t_info *info, char *filename, int type)
{
//	if (type == TYPE_REIN)
//	{
//		info->fd_in_idx++;
//		info->fd_in[info->fd_in_idx] = open(filename, O_CREAT | O_TRUNC | O_RDONLY, 0755);
//	}
//	if (type == TYPE_REOUT)
//	{
//		info->fd_out_idx++;
//		info->fd_out[info->fd_out_idx] = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0755);
//	}
//	if (type == TYPE_REOUT_D)
//	{
//		info->fd_out_idx++;
//		info->fd_out[info->fd_out_idx] = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0755);
//	}
//	printf("info->fd_in_idx: %d\n", info->fd_in_idx);
//	printf("info->fd_out_idx: %d\n", info->fd_out_idx);
	return (0);
}

int			set_redir_info(t_info *info, char *str, int type)
{
	int		ret;
	int		idx;
	char	*filename;

	filename = NULL;
	idx = seek_filename(str, &filename, type);
	if (idx == -1)
		return (-1);
	ret = is_valid_filename(filename, type);
	if (ret && idx)
		ret = set_fd_info(info, filename, type);
	free(filename);
	if (ret)
		return (idx);
	return (ret);
}
// if there is two file names, treat first one only.
// second one treat like args.
// echo abc >> test.txt test2.txt -> work
//			cat test.txt 
//			result : abc test2.txt
// ls -al >> test.txt test2.txt -> error occured.

