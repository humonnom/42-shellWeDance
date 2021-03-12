#include "../incs/minishell.h"

static int	is_n_flag(char *str)
{
	int ret;
	int idx;

	ret = 0;
	idx = 0;
	if (str[idx] == '-')
		ret = 1;
	while (ret == 1 && str[++idx])
	{
		if (str[idx] != 'n')
			ret = 0;
	}
	return (ret);
}
#if 0
char	*get_squote_part(char **str)
{
}
#endif

static char	*get_dquote_part(char **str_addr, t_list *env_list)
{
	int		idx;
	char	*str;
	char	*prev_ret;
	char	*tmp;
	char	*ret;

	str = *str_addr;
	idx = 0;
	if (!is_dquote(str[idx++]))
		return (NULL);
	ret = ft_strdup("");
	prev_ret = ret;
	while (!is_dquote(str[idx]))
	{
		if (str[idx] == '$')
			tmp = get_dollar_eval(&str[idx], env_list, &idx);
		else
			tmp = change_char2str(str[idx++]);
		ret = ft_strjoin(ret, tmp);
		free(prev_ret);
		prev_ret = ret;
		free(tmp);
	}
	*str_addr = *str_addr + idx + 1;
	return (ret);	
}

char	*get_part(char *arg, t_list *env_list)
{
	char	*ret;
	char	*tmp;

	while (*arg)
	{
		if (is_dquote(*arg))
		{
			tmp = get_dquote_part(&arg, env_list);	
			printf("after double quote: %s\n", arg);
		}
		++arg;
	}
	ret = tmp;
	return (ret);
}

int	sh_bti_echo(char **args, t_list *env_list)
{
	int	idx;
	int	n_flag;

	n_flag = 0;
	idx = -1;
	while (args[++idx] && is_n_flag(args[idx]))
		n_flag = 1;
	idx--;
	while (args[++idx])
	{
		if (idx >= 1)
			break;
		char *tmp = get_part(args[idx], env_list);
		write(STDOUT_FILENO, tmp, ft_strlen(tmp));
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (0);
}
