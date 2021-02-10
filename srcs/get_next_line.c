#include "minishell.h"

int get_next_line(char **line) {
	int read_size = 1;
	char buf[2];
	char *backup;

	backup = ft_strjoin("", "");
	while (read_size > 0 && buf[0] != '\n') {
		read_size = read(STDIN_FILENO, buf, 1);
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
