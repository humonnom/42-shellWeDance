#include "../incs/minishell.h"

t_set *gen_set(t_info *info, char *set_str)
{
	char	*set_fd_res;
	char	*set_fd_res_cpy;
	char	**tmp_set;
	t_set	*ret;

	if (!(ret = (t_set *)malloc(sizeof(t_set))))
		return (NULL);
	set_fd_res = set_fd(ret, set_str);
	if (set_fd_res == NULL)
		return (NULL);
	set_fd_res_cpy = ft_strdup(set_fd_res);
	handle_quote(set_str, &set_fd_res_cpy, ' ');
	if (!(tmp_set = pk_split(set_fd_res, set_fd_res_cpy, ' ', INF)))
		return (NULL);
	ret->set = tmp_set;
	ret->cmd = ft_strdup(tmp_set[0]);
	ret->args = &tmp_set[1];
	free(set_fd_res);
	free(set_fd_res_cpy);
    return (ret);
}
