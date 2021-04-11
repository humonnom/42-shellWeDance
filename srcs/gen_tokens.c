#include "../incs/minishell.h"

t_tokens *gen_tokens(t_info *info, char *set_str)
{
	char		*set_fd_res;
	char		*set_fd_res_cpy;
	char		**tmp_tokens;
	t_tokens	*ret;

	if (!(ret = (t_tokens *)malloc(sizeof(t_tokens))))
		return (NULL);
	set_fd_res = set_fd(ret, set_str);
	if (set_fd_res == NULL)
		return (NULL);
	set_fd_res_cpy = ft_strdup(set_fd_res);
	handle_quote(set_str, &set_fd_res_cpy, ' ');
	if (!(tmp_tokens = pk_split(set_fd_res, set_fd_res_cpy, ' ', INF)))
		return (NULL);
	ret->tokens = tmp_tokens;
	ret->cmd = ft_strdup(tmp_tokens[0]);
	ret->args = &tmp_tokens[1];
	free(set_fd_res);
	free(set_fd_res_cpy);
    return (ret);
}
