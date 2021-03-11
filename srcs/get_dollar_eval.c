#include "../incs/minishell.h"

static int	is_finish_cond(char c)
{
	if (c == '\"')
		return (1);
	if (c == '\'')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static int	inc_part(char *part)
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

char	*get_dollar_eval(char **part_addr, t_list *env_list)
{
	char	*ret;
	int		len;
	char	*part;
	int		dollor_eval_len;
	char	*tmp_key;

	part = *part_addr;
	if (part[0] != '$')
		return (NULL);
	len = inc_part(*part_addr);
	//$
	if (len == 0)
	{
		*part_addr = *part_addr + 1;
		return (ft_strdup("$"));	
	}
	//$$
	//$?
	//$HOME
	*part_addr = *part_addr + len;
	tmp_key = ft_substr(part, 1, len - 1);
	ret = get_eval(env_list, tmp_key);
	free(tmp_key);
	return (ret);
}
