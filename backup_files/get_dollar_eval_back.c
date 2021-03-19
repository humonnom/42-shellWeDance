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

char	*get_dollar_eval(char *arg, t_list *env_list)
{
	int		idx;
	int		len;
	char	*var;
	char	*ret;

	idx = -1;
	len = get_dollar_len(arg);
//	while (arg[++idx] && arg[idx] != '\'' && arg[idx] != '\"' && arg[idx] != '$')
//		len++;
	if (len == 0)
		return (NULL);
	if (!(var = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	var[len] = '\0';
	idx = -1;
	while(++idx < len)
		var[idx] = arg[idx];
	if (!(ret = get_eval(env_list, var)))
		return (NULL);
	free(var);
	return(ret);
}
