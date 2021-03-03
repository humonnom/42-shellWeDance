#include "../incs/minishell.h"

static int	get_alist(
			t_list **list_head,
			char **str)
{
	int		ret;
	int		len;
	t_list	*tmp_list;
	char	*tmp_set;

	ret = 0;	
	len = 0;
	while (ret == 0 && str[len])
		len++;
	while (ret == 0 && --len >= 0)
	{
		if (!(tmp_set = ft_strdup(str[len])))
			ret = 1;
		tmp_list = ft_lstnew(tmp_set);
		ft_lstadd_front(list_head, tmp_list);
	}
	return (ret);
}

t_set *parse_set_arr(char *set_str)
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
	if (!(tmp_set = pk_split(set_str, set_str, ' ', INF)))
		error_num = turn_on_bit(error_num, 1);
#if 0
	if (!error_num && get_alist(&ret, arg_part))
		error_num = turn_on_bit(error_num, 2);
#endif
	if (!(ret = (t_set *)malloc(sizeof(t_set))))
		return (NULL);
	ret->cmd = tmp_set[0];
	ret->args = &tmp_set[1];
	if (error_num)
		return (NULL);
    return (ret);
}
