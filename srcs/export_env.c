#include "../incs/minishell.h"

int	get_eq_idx(char *set_cpy)
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

int	export_env(t_list **list_head, char *set)
{
	char	*set_cpy;
	char	**key_part;
	char	**val_part;
	char	*key;
	int		tmp;

	if (!(set_cpy = ft_strdup(set)))
		return (-1);
	if (handle_quote(set, &set_cpy, '=') > 0)
		return (-1);
	if ((key_part = pk_split(set, set_cpy, '=', 1)) == 0)
		return (-1);
	tmp = get_eq_idx(set_cpy) + 1;
	if ((val_part = pk_split(&set[tmp], &set_cpy[tmp], ' ', 1)) == 0)
		return (-1);
	if (get_list_index(*list_head, key_part[0]) >= 0)
		modify_list_data(list_head, key_part[0], val_part[0]);	
	else
		add_list_data(list_head, key_part[0], val_part[0]);	
	pk_split_free(key_part);
	pk_split_free(val_part);
	return (0);	
}
