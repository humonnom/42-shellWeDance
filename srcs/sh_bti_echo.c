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

static int print_with_var(char *arg, t_list *env_list)
{
	char	*var;
	int		len;

	if (!(var = get_dollar_eval(arg, env_list)))
		return (0);
	write (STDOUT_FILENO, var, ft_strlen(var));
	return (get_dollar_len(arg));
}
char *var;
var = get_var();
var -> HOME
idx += ft_strlen(var);
char *ret;
ret = get_eval(env_list, var);
buf <- ret copy
static int	handle_arg(char *buf, char *arg, t_list *env_list)
{
	int idx;
	int	buf_idx;
	int	s_flag;
	int	d_flag;

	s_flag = 0;
	d_flag = 0;
	idx = -1;
	buf_idx = 0;
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
			idx += get_dollar_len(&arg[idx + 1]);
		else
			buf[buf_idx++] = arg[idx];
	}
	return (0);
}

echo "a'b'c"/$/""/HOME/'d"e"f'

' ' -> save(buf)
" " -> handle_dollar(without d_quote)
[ ] -> handle_dollar


int	sh_bti_echo(char **args, t_list *env_list)
{
	int		ret;
	int		idx;
	int		n_flag;
	char	buf[BUF_SIZE];

	ret = 0;
	n_flag = 0;
	idx = -1;
	while (args[++idx] && is_n_flag(args[idx]))
		n_flag = 1;
	while (args[idx])
	{
		handle_arg(buf, args[idx], env_list);
		if (args[idx + 1])
			write(1, " ", 1);
		idx++;
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (ret);
}
