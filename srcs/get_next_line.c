#include "../incs/minishell.h"
static void	handle_eof(t_info *info, char *backup)
{
	if (ft_strlen(backup) == 0)
	{
		free(backup);
		g_cmd_ret = 0;
		g_ret = 0;
		exit_shell(info);
	}
	else
		write(1, "  \b\b", 4);
}

static char	handle_newline(int backup_len, char buf, int read_size)
{
	int ret;

	ret = 0;
	if((backup_len == 0) && buf == '\n' && read_size == 1)
	{
		display_prompt();
		ret = 1;
	}
	return (ret);
}

int			get_next_line(t_info *info, char **line)
{
	int read_size = 1;
	char buf[2];
	char *backup;

	backup = ft_strjoin("", "");
	while (read_size >= 0 && buf[0] != '\n')
	{
		read_size = read(STDIN_FILENO, buf, 1);
		buf[1] = '\0';
	//	printf("buf: %s	read_size: %d\n", buf, read_size);
		if (read_size == 0)
			handle_eof(info, backup);
		else if (buf[0] != '\n' && read_size >= 0)
		{
			char *tmp = backup;
			backup = ft_strjoin(backup, buf);
			free(tmp);
		}
		else if (handle_newline(ft_strlen(backup), buf[0], read_size))
			buf[0] = '\0';
	}
	*line = backup;
	return (read_size);
}
