/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:16:24 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:41:22 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

static int
	get_eq_idx(char *set_cpy)
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

static char
	*get_item(char *str, char *str_cpy, char delimit)
{
	char	**tab;
	char	*ret;

	if ((tab = pk_split(str, str_cpy, delimit, 1)) == 0)
		return (NULL);
	ret = ft_strdup(tab[0]);
	free_darr(tab, 1);
	return (ret);
}

static t_env
	*get_env_form(char *key, char *val)
{
	t_env	*ret;

	ret = NULL;
	if (!(ret = (t_env *)malloc(sizeof(t_env))))
		return (ret);
	ret->key = key;
	ret->val = val;
	return (ret);
}

t_env
	*gen_env(char *str)
{
	char	*str_cpy;
	char	*key;
	char	*val;
	int		eq_idx;

	if (!(str_cpy = ft_strdup(str)))
		return (NULL);
	if (handle_quote(str, &str_cpy, '=') > 0)
		return (NULL);
	if (str_cpy[0] == '=')
		key = ft_strdup("");
	else if (!(key = get_item(str, str_cpy, '=')))
		return (NULL);
	eq_idx = get_eq_idx(str_cpy) + 1;
	if (eq_idx == 0)
		val = ft_strdup("");
	else if (!(val = get_item(&str[eq_idx], &str_cpy[eq_idx], ' ')))
		return (NULL);
	free(str_cpy);
	return (get_env_form(key, val));
}
