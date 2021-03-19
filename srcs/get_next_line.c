#include "../incs/minishell.h"

int get_next_line(t_info *info, char **line) 
{
	int read_size = 1;
	char buf[2];
	char *backup;

	backup = ft_strjoin("", "");
	while (read_size >= 0 && buf[0] != '\n')
	{
		read_size = read(STDIN_FILENO, buf, 1);
		buf[1] = '\0';
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
