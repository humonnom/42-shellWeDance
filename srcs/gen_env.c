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

static char	*get_item(char *str, char *str_cpy, char delimit)
{
	char	**tab;
	char	*ret;

	if ((tab = pk_split(str, str_cpy, delimit, 1)) == 0)
		return (NULL);
	ret = ft_strdup(tab[0]);
	free_darr(tab, 1);
	return (ret);
}

static t_env	*get_env_form(char *key, char *val)
{
	t_env	*ret;

	ret = NULL;
	if (!(ret = (t_env *)malloc(sizeof(t_env))))
		return (ret);
	ret->key = key;
	ret->val = val;
	return (ret);
}

t_env	*gen_env(char *str)
{
	char	*str_cpy;
	char	*key;
	char	*val;
	int		eq_idx;
	t_list	*tmp_elist;

	if (!(str_cpy = ft_strdup(str)))
		return (NULL);
	if (handle_quote(str, &str_cpy, '=') > 0)
		return (NULL);
	if (str_cpy[0] == '=')
		key = ft_strdup("");
	else if (!(key = get_item(str, str_cpy, '=')))
		return (NULL);
	eq_idx = get_eq_idx(str_cpy) + 1;
	// in case that export has only key without val
	if (eq_idx == 0)
		val = ft_strdup("");
	else if (!(val = get_item(&str[eq_idx], &str_cpy[eq_idx], ' ')))
		return (NULL);
	// in case that finding key in env_list
	free(str_cpy);
	return (get_env_form(key, val));	
}
