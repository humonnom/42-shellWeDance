#include "../incs/minishell.h"

static char	handle_enter(
			int backup_len,
			char buf,
			int read_size)
{
	int ret;

	ret = 0;
	if((backup_len == 0) && buf == '\n' && read_size == 1)
	{
		//display_prompt();
		ret = 1;
	}
	return (ret);
}

static char	*handle_fflush(char *backup)
{
	char *ret;

	free(backup);
	backup = NULL;
	ret = ft_strjoin("", "");
	g_fsh_buf = 0; 
	return (ret);
}

static void	handle_eof(t_info *info, char *backup)
{
	if (ft_strlen(backup) == 0)
	{
		free(backup);
		g_ret = 0;
		g_ret = exit_shell(info);
		exit(0);
	}
	ft_putstr_fd("  \b\b", STDERR_FILENO);
}

int 		get_next_line(t_info *info, char **line) 
{
	int read_size = 1;
	char buf[2];
	char *backup;

	backup = ft_strjoin("", "");
	while (read_size >= 0 && buf[0] != '\n')
	{
		read_size = read(STDIN_FILENO, buf, 1);
		buf[1] = '\0';
		if (g_fsh_buf)
			backup = handle_fflush(backup);
		if (read_size == 0)
			handle_eof(info, backup);
		else if (buf[0] != '\n' && read_size > 0) 
		{
			char *tmp = backup;
			backup = ft_strjoin(backup, buf);
			free(tmp);
		}
		else if (handle_enter(ft_strlen(backup), buf[0], read_size))
			buf[0] = '\0';
	}
	*line = backup;
	return (read_size);
}
