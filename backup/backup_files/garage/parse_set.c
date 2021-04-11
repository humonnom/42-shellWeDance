#include "../incs/minishell.h"

// malloc for original cmd(count size),
// remove " or '
// use strcmp for checking if word is cmd or not

//arg_list->data : echo " a" char *arg = echo " a" char *arg_cpy = echo "0a" args = [echo, " a"]
//-> { echo " a" }

// line: single command and argument set
// word: [command, argument1, ...]
// in case that cmd = "ec""ho" ..

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

t_list *gen_set_list(char *set)
{
    char	*set_cpy;
	char	**arg_part;
    int		error_num;
	t_list	*ret;
	
	ret = NULL;
    error_num = 0;
    if (!(set_cpy = ft_strdup(set)))
		return (NULL);
	if (handle_quote(set, &set_cpy, ' ') > 0)
		error_num = turn_on_bit(error_num, 0);
	if (!(arg_part = pk_split(set, set_cpy, ' ', INF)))
		error_num = turn_on_bit(error_num, 1);
	if (!error_num && get_alist(&ret, arg_part))
		error_num = turn_on_bit(error_num, 2);
	free (set_cpy);
	if (!check_bit(error_num, 1))
		free_darr(arg_part, INF);
	if (error_num)
		return (NULL);
    return (ret);
}
