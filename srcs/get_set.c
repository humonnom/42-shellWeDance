#include "../incs/minishell.h"
static char	*handle_quote_redir(char *set_str)
{
	char	*ret;
	char	*src_cpy;
	char	*src;
	int		error_num;

	src = set_str;
	src_cpy = ft_strdup(set_str);
	if (handle_quote(src, &src_cpy, '<') > 0)
		error_num = turn_on_bit(error_num, 0);
	free(src);
	src = ft_strdup(src_cpy);
	if (handle_quote(src, &src_cpy, '>') > 0)
		error_num = turn_on_bit(error_num, 0);
	free(src);
	ret = src_cpy;
	return (ret);
}
	

t_set *get_set(t_info *info, char *set_str)
{
    char	*set_str_cpy;
    int		error_num;
	char	**tmp_set;
	t_set	*ret;

	ret = NULL;
    error_num = 0;
	set_str = ft_strdup(set_str);
    if (!(set_str_cpy = ft_strdup(set_str)))
		return (NULL);
	if (handle_quote(set_str, &set_str_cpy, ' ') > 0)
		error_num = turn_on_bit(error_num, 0);
	if (!(set_str_cpy = handle_quote_redir(set_str_cpy)))
		return (NULL);
	printf("after handle_quote redir: %s\n", set_str_cpy);
	set_str = parse_redir(info, set_str, set_str_cpy);
	if (!set_str)
		error_num = turn_on_bit(error_num, 0);
	int idx = -1;
//	while (set_str[++idx])
//		printf("after parse_redir: %c\n", set_str[idx]);
	//free(str);
	free(set_str_cpy);
	set_str_cpy = ft_strdup(set_str);
	if (!(tmp_set = pk_split(set_str, set_str_cpy, ' ', INF)))
		error_num = turn_on_bit(error_num, 1);
	free(set_str_cpy);
	idx = -1;
	while (tmp_set[++idx])
		printf("[args] :%s\n", tmp_set[idx]);
	if (!(ret = (t_set *)malloc(sizeof(t_set))))
		return (NULL);
	ret->set = tmp_set;
	ret->cmd = ft_strdup(tmp_set[0]);
	ret->args = &tmp_set[1];
	free(set_str);
	if (error_num)
		return (NULL);
    return (ret);
}
