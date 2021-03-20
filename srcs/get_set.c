#include "../incs/minishell.h"

g_fds[1024];
g_k;

// in exit
for (i = 0; i < g_k; ++i)
	close(g_fds[i]);

// in init_minishell
//init_minishell -> g_k = 0;

void handle_redirect(char **tmp_set) {

	// use get_bti_path function in run_bti
	// to check if command or file name

	// nothing after > | < | << -> showerror(\n error ~)

	while (< | > | >>)
		idx++
		break

	while (tmp_set[idx])
	{
		
		if <
			tmp_fd = open("test.txt", O_CREAT | O_TRUNC | O_RDONLY, 0755);
			dup2(g_fds[g_k++], STDIN_FILENO)
		if >
			tmp_fd = open("test.txt", O_CREAT | O_TRUNC | O_WRONLY, 0755);
			// test after closing tmp_fd write something on STDOUT
			dup2(tmp_fd, STDOUT_FILENO)
		if >>
			tmp_fd = open("test.txt", O_CREAT | O_APPEND | O_WRONLY, 0755);
			dup2(tmp_fd, STDOUT_FILENO)
	}

	// free after last args
	
}

t_set *get_set(char *set_str)
{
    char	*set_str_cpy;
    int		error_num;
	char	**tmp_set;
	t_set	*ret;
	
	ret = NULL;
    error_num = 0;
    if (!(set_str_cpy = ft_strdup(set_str)))
		return (NULL);
	if (handle_quote(set_str, &set_str_cpy, ' ') > 0)
		error_num = turn_on_bit(error_num, 0);
	if (!(tmp_set = pk_split(set_str, set_str_cpy, ' ', INF)))
		error_num = turn_on_bit(error_num, 1);
	free(set_str_cpy);
	if (!(ret = (t_set *)malloc(sizeof(t_set))))
		return (NULL);
	ret->set = tmp_set;
	ret->cmd = ft_strdup(tmp_set[0]);
	ret->args = &tmp_set[1];
	if (error_num)
		return (NULL);
    return (ret);
}
