#include "../incs/minishell.h"

char	*get_dollar_eval(char *arg, t_list *env_list)
{
	int		idx;
	int		len;
	char	*var;
	char	*ret;

	idx = -1;
	len = 0;
	while (arg[++idx] && arg[idx] != '\'' && arg[idx] != '\"' && arg[idx] != '$')
		len++;
	if (!(var = (char *)malloc(sizeof(char) * (len + 1))))
		return (len);
	var[len] = '\0';
	idx = -1;
	while(++idx < len)
		var[idx] = arg[idx];
	if ((ret = get_eval(env_list, var)))
		write(1, ret, ft_strlen(ret));
	return(var);
}
