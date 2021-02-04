#include "get_next_line.h"

static int ft_strlen(char *str) {
	int ret = 0;
	for (; str[ret]; ++ret);
	return (ret);
}

static char *ft_strjoin(char *str1, char *str2) {
	char *ret;

	int tot_len = ft_strlen(str1) + ft_strlen(str2);
	if (!(ret = (char *)malloc(sizeof(char) * (tot_len + 1))))
		return (NULL);
	ret[tot_len] = '\0';

	int k = 0;
	for (int i = 0; str1[i]; ++i)
		ret[k++] = str1[i];
	for (int i = 0; str2[i]; ++i)
		ret[k++] = str2[i];

	return (ret);
}

int get_next_line(char **line) {
	int read_size = 1;
	char buf[2];
	char *backup;

	backup = ft_strjoin("", "");
	while (read_size > 0 && buf[0] != '\n') {
		read_size = read(3, buf, 1);
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
