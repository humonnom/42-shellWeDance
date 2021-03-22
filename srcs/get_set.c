#include "../incs/minishell.h"

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
	// insert ' ' -> side of "<, >, >>"
	if (handle_quote(set_str, &set_str_cpy, ' ') > 0)
		error_num = turn_on_bit(error_num, 0);
	if (!(tmp_set = pk_split(set_str, set_str_cpy, ' ', INF)))
		error_num = turn_on_bit(error_num, 1);
	free(set_str_cpy);
	tmp_set = handle_redirect(tmp_set);
//	int idx = -1;
//	while (tmp_set[++idx])
//		printf("after handle_redirect: %s\n", tmp_set[idx]);
	if (!(ret = (t_set *)malloc(sizeof(t_set))))
		return (NULL);
	ret->set = tmp_set;
	ret->cmd = ft_strdup(tmp_set[0]);
	ret->args = &tmp_set[1];
	if (error_num)
		return (NULL);
    return (ret);
}
