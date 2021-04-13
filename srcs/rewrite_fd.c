#include "../incs/minishell.h"

static int	get_next_line_fd(char **line, int fd)
{
	int read_size = 1;
	char buf[2];
	char *backup;

	backup = ft_strjoin("", "");
	while (read_size > 0 && buf[0] != '\n') {
		read_size = read(fd, buf, 1);
		buf[1] = '\0';
		if (buf[0] != '\n' && read_size > 0) {
			char *tmp = backup;
			backup = ft_strjoin(backup, buf);
			free(tmp);
		}
	}
	*line = backup;
	return (read_size);
}

int	rewrite_fd(t_info *info, char *file_name, int fd2)
{
	int	fd;
	int	ret;
	char	*line;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		printf("file_name not opened\n");
		return (1);
	}
	while (get_next_line_fd(&line, fd) > 0)
	{
		ft_putstr_fd(line, fd2);
		write(fd2, "\n", 1);
		free(line);
	}
	free(line);
	
	return (ret);
}
