#include "../incs/minishell.h"

static int	get_eq_idx(char *set_cpy)
{
	int	ret;

	ret = 0;
	while (*set_cpy)
	{
		if (*set_cpy == '=')
			return (ret);
		++set_cpy;
		++ret;
	}
	return (-1);
}
static t_env	*gen_elist_data(char *key, char *val)
{
	t_env	*ret;

	if (!(ret = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(ret->key = ft_strdup(key)))
		return (NULL);
	if (!(ret->val = ft_strdup(val)))
		return (NULL);
	return (ret);
}
char	*get_elist_data_part(
		char *set,
		char *set_cpy, 
		char charset,
		int limit)
{
	char 	**part;
	char	*ret;
	int		err_num;

	err_num = 0;
	if ((part = pk_split(set, set_cpy, charset, limit)) == 0)
		err_num = turn_on_bit(err_num, 0);
	if (!check_bit(err_num, 0) && !(ret = ft_strdup(part[0])))
		err_num = turn_on_bit(err_num, 1);
	if (!check_bit(err_num, 0))
		free_darr(part, 1);
	if (!ret)
		ret = ft_strdup("");
	return (ret);
}

t_env	*parse_env(char *set)
{
	char	*key;
	char	*val;
	char	*set_cpy;
	int		tmp;
	t_env	*ret;

	if (!(set_cpy = ft_strdup(set)))
		return (NULL);
	if (handle_quote(set, &set_cpy, '=') > 0)
		return (NULL);
	key = get_elist_data_part(set, set_cpy, '=', 1);
	tmp = get_eq_idx(set_cpy) + 1;
	val = get_elist_data_part(&set[tmp], &set_cpy[tmp], ' ', 1);
	if (!(ret = gen_elist_data(key, val)))
		return (NULL);
	free(set_cpy);
	return (ret);	
}
