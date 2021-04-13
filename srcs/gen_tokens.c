#include "../incs/minishell.h"

<<<<<<< HEAD
t_tokens *gen_tokens(t_info *info, char *line)
=======
t_tokens *gen_tokens(t_info *info, char *set_str)
>>>>>>> df52ce4be677ec57d998a3f41ac1db1c54c05c33
{
	char		*set_fd_res;
	char		*set_fd_res_cpy;
	char		**tmp_tokens;
	t_tokens	*ret;

	if (!(ret = (t_tokens *)malloc(sizeof(t_tokens))))
		return (NULL);
<<<<<<< HEAD
	set_fd_res = set_fd(ret, line);
	if (set_fd_res == NULL)
		return (NULL);
	set_fd_res_cpy = ft_strdup(set_fd_res);
	handle_quote(line, &set_fd_res_cpy, ' ');
=======
	set_fd_res = set_fd(ret, set_str);
	if (set_fd_res == NULL)
		return (NULL);
	set_fd_res_cpy = ft_strdup(set_fd_res);
	handle_quote(set_str, &set_fd_res_cpy, ' ');
>>>>>>> df52ce4be677ec57d998a3f41ac1db1c54c05c33
	if (!(tmp_tokens = pk_split(set_fd_res, set_fd_res_cpy, ' ', INF)))
		return (NULL);
	ret->tokens = tmp_tokens;
	ret->cmd = ft_strdup(tmp_tokens[0]);
	ret->args = &tmp_tokens[1];
	free(set_fd_res);
	free(set_fd_res_cpy);
    return (ret);
}
