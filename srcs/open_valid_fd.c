#include "../incs/minishell.h"

static char	*get_file_name(
			char *str,
			int *inc_idx)
{
	int		beg;
	int		end;
	char	*ret;

	while (str[*inc_idx] && str[*inc_idx] == ' ')
		++(*inc_idx);
	beg = *inc_idx;
	while (str[*inc_idx] && str[*inc_idx] != ' '
			&& !is_bracket(str[*inc_idx]))
		++(*inc_idx);
	end = *inc_idx;
	ret = ft_substr(str, beg, end - beg);
	if (!ret)
		return (NULL);
	return (ret);
}

int	open_valid_fd(t_tokens *tokens, char *set_str, int *idx, int type)
{
	int		fd;
	char	*file_name;
	int		inc_idx;

	inc_idx = 0;
	file_name = get_file_name(set_str, &inc_idx);
	printf("open_valid_fd::file_name: %s\n", file_name);
	if (type & TYPE_REIN)
		fd = open(file_name, O_RDONLY);
	if (type & TYPE_REOUT)
		fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0755);
	if (type & TYPE_REOUT_D)
		fd = open(file_name, O_CREAT | O_APPEND | O_WRONLY, 0755);
	if (fd < 0)
		return (0);
	if (type & TYPE_REIN)
		tokens->fd_in[++(tokens->fd_in_idx)] = fd;
	if (type & (TYPE_REOUT | TYPE_REOUT_D))
		tokens->fd_out[++(tokens->fd_out_idx)] = fd;
	free(file_name);
	*idx += inc_idx;
	return (1);
}
