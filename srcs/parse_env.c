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

t_env	*parse_env(char *set)
{
	char	*set_cpy;
	char	**key_part;
	char	**val_part;
	int		tmp;
	t_env	*ret;

	if (!(set_cpy = ft_strdup(set)))
		return (NULL);
	if (handle_quote(set, &set_cpy, '=') > 0)
		return (NULL);
	if ((key_part = pk_split(set, set_cpy, '=', 1)) == 0)
		return (NULL);
	tmp = get_eq_idx(set_cpy) + 1;
	if ((val_part = pk_split(&set[tmp], &set_cpy[tmp], ' ', 1)) == 0)
		return (NULL);
	if (!(ret = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(ret->key = ft_strdup(key_part[0])))
		return (NULL);
	if (!(ret->val = ft_strdup(val_part[0])))
		return (NULL);
	pk_split_free(key_part);
	pk_split_free(val_part);
	return (ret);	
}
