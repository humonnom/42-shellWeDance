#include "../incs/minishell.h"
static int	get_dollar_len(char *arg)
{
	int		idx;
	int		len;
	char	*var;
	char	*ret;

	idx = -1;
	len = 0;
	while (arg[++idx] && arg[idx] != '\'' && arg[idx] != '\"' && arg[idx] != '$')
		len++;
	return (len);
}

char	*get_dollar_eval(char *part, t_list *env_list)
{
	char	*ret;
	//$

	//$$

	//$?

	//$HOME
	$HOMEabc
		/abc/"$HOME"/abc/''
		/"$HOME abc"
	return(ret);
}
