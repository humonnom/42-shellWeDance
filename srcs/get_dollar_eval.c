#include "../incs/minishell.h"

static int	is_finish_cond(char c)
{
	if (c == '\"')
		return (1); if (c == '\'') return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static int	get_word_len(char *part)
{
	int	ret;

	ret = 0;
	while (part[ret])
	{
		if (is_finish_cond(part[ret]))
			return (ret);
		++ret;
	}
	return (ret);
}

char	*get_dollar_eval(char *part, t_list *env_list, int *idx)
{
	char	*ret;
	int		word_len;
	int		dollor_eval_len;
	char	*tmp_key;

	if (part[0] != '$')
		return (NULL);
	word_len = get_word_len(part);
	//$
	if (word_len == 1)
	{
		*idx = *idx + word_len;
		return (ft_strdup("$"));
	}
	//$$
	//$? 
#if 0
	if ((ft_strncmp("$?", part, get_max_strlen("$?", part))) == 0)
	{
		*idx = *idx + word_len;
		return (ft_itoa(g_ret));	
	}
#endif
	//$HOME
	tmp_key = ft_substr(part, 1, word_len - 1);
	ret = ft_strdup(get_eval(env_list, tmp_key));
	*idx = *idx + word_len;
	free(tmp_key);
	tmp_key = NULL;
	return (ret);
}
