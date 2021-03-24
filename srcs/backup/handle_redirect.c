#include "../incs/minishell.h"
static void	remove_bracket(char **tmp_set, int tmp_idx)
{
	while (tmp_set[tmp_idx])
	{
		printf("free: %s\n", tmp_set[tmp_idx]);
		free(tmp_set[tmp_idx]);
		tmp_set[tmp_idx++] = 0;
	}
}


static int is_valid_filename(char *file_name, int type)
{
	char	s[PATH_MAX];
	char	*cwd;
	char	*path;
	int		ret;

	ret = 0;
	if (file_name == NULL)
		printf("zsh: parse error near `\n'");
	else if (is_bracket(file_name))
		printf("zsh: parse error near `%s'\n", file_name);
	else if (type == TYPE_REIN)
	{
		cwd = getcwd(s, PATH_MAX);
		path = get_bti_path(cwd, file_name);
		if (!path)
			printf("zsh: no such file or directory: %s\n", file_name);
		free(path);
	}
	else
		ret = 1;
	return (ret);
}

static int modify_fd(char *file_name, int type)
{
	int ret;

	ret = 1;
	printf("modify fd!\n");
	if (type == TYPE_REIN) // <
	{
		printf("type: <, %s is open\n", file_name);
//		g_fds[g_k] = open(file_name, O_CREAT | O_TRUNC | O_RDONLY, 0755);
//		dup2(g_fds[g_k++], STDIN_FILENO);
	}
	else if (type == TYPE_REOUT) // >
	{
		printf("type: >, %s is open\n", file_name);
//		g_fds[g_k] = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0755);
//		dup2(g_fds[g_k++], STDOUT_FILENO);
	}
	else if (type == TYPE_REOUT_D) // >>
	{
//		printf("type: >>, %s is open\n", file_name);
		g_fds[g_k] = open(file_name, O_CREAT | O_APPEND | O_WRONLY, 0755);
		if (g_k == 0)
			dup2(g_fds[g_k], STDOUT_FILENO);
		else
			g_fds[g_k] = dup(g_fds[g_k - 1]);
		g_k++;
	}
	else
		ret = 0;
	return (ret);
}

// test after closing fd write something on STDOUT
char			**handle_redirect(char **tmp_set)
{
	int 	idx;
	int		tmp_idx;
	int		type;
	int		ret;

	ret = 0;
	idx = 0;
	while (tmp_set[idx] && !(is_bracket(tmp_set[idx])))
		idx++;
	tmp_idx = idx;
	while (ret > -1 && tmp_set[idx])
	{
		type = is_bracket(tmp_set[idx]);
		if (type)
		{
			if (is_valid_filename(tmp_set[idx + 1], type))
				ret = modify_fd(tmp_set[++idx], type);
			else
				ret = -1;
		}
		idx++;
	}
	if (ret > 0)
		remove_bracket(tmp_set, tmp_idx);
	return (tmp_set);
}
