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

static int print_with_var(char *arg, t_list *env_list)
{
	int		idx;
	int		len;
	char	*var;
	char	*ret;

	idx = -1;
	len = 0;
	while (arg[++idx] && arg[idx] != '\'' && arg[idx] != '\"' && arg[idx] != '$')
		len++;
	if (!(var = (char *)malloc(sizeof(char) * len + 1)))
		return (len);
	var[len] = '\0';
	idx = -1;
	while(++idx < len)
		var[idx] = arg[idx];
	if ((ret = get_eval(env_list, var)))
		write(1, ret, ft_strlen(ret));
	free(var);
	return (len);
}

static int	handle_arg(char *arg, t_list *env_list)
{
	int idx;
	int	s_flag;
	int	d_flag;

	s_flag = 0;
	d_flag = 0;
	idx = -1;
	while (arg[++idx])
	{
		if (d_flag == 0 && s_flag == 0 && arg[idx] == '\'')
			s_flag = 1;
		else if (d_flag == 0 && s_flag == 1 && arg[idx] == '\'')
			s_flag = 0;
		else if (s_flag == 0 && d_flag == 0 && arg[idx] == '\"')
			d_flag = 1;
		else if (s_flag == 0 && d_flag == 1 && arg[idx] == '\"')
			d_flag = 0;
		else if (arg[idx] == '$' && s_flag == 0)
			idx += print_with_var(&arg[idx + 1], env_list);
		else
			write(1, &arg[idx], 1);
	}
	return (0);
}

int	sh_bti_echo(char **args, t_list *env_list)
{
	int ret;
	int idx;
	int	n_flag;
	int	*q_flag;
	char *str;

	ret = 0;
	n_flag = 0;
	idx = -1;
	while (args[++idx] && is_n_flag(args[idx]))
		n_flag = 1;
	while (args[idx])
	{
		handle_arg(args[idx], env_list);
		if (args[idx + 1])
			write(1, " ", 1);
		idx++;
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (ret);
}
