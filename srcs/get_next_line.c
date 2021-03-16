#include "../incs/minishell.h"
static	void handle_eof(char *backup)
{
	if (ft_strlen(backup) == 0)
	{
		free(backup);
		//free
		exit(0);
	}
	else
	{
		write(1, "  \b\b", 4);
	}
}

int get_next_line(char **line) {
	int read_size = 1;
	char buf[2];
	char *backup;

	backup = ft_strjoin("", "");
	while (read_size >= 0 && buf[0] != '\n') {
		read_size = read(STDIN_FILENO, buf, 1);
		buf[1] = '\0';
	//	printf("buf: %s	read_size: %d\n", buf, read_size);
		if (read_size == 0)
			handle_eof(backup);
		if (buf[0] != '\n' && read_size >= 0) {
			char *tmp = backup;
			backup = ft_strjoin(backup, buf);
			free(tmp);
		}
	}
	*line = backup;
	return (read_size);
}
