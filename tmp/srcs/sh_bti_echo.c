#include "../incs/minishell.h"
static int get_letter_idx(char *str, int idx, int step, char letter)
{
	while (idx >= 0 && str[idx])
	{
		if (str[idx] == letter)
			return (idx);
		idx += step;
	}
	return (-1);
}
//static void print_with_val(char *arg, t_list *env_list)
//{
//	int		idx;
//	int		len;
//	int		std;
//	char	*str;
//	char	*val;
//
//	std = get_letter_idx(arg, 0, 1, '$');
//	idx = -1;
//	while (++idx < std)
//		write(1, &arg[idx], 1);
//	if ((val = get_eval(env_list, &arg[std + 1])))
//		write(1, val, ft_strlen(val));
//}

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


//static void	print_quote_set(char *str, char quote, t_list *env_list)
//{
//	char	str_cpy;
//	int s_quote_frst;
//	int s_quote_last;
//	int std;
//	int idx;
//	
//	s_quote_frst = get_letter_idx(str, 0, 1, quote);
//	s_quote_last = get_letter_idx(str, ft_strlen(str) - 1, -1, quote);
//	std = get_letter_idx(str, 0, 1, '$');
//	idx = -1;
//	if (std != -1 && quote == '\"' && std > s_quote_frst && std < s_quote_last)
//	{
//		print_with_val(str, env_list);
//		return ;
//	}
//	while (str[++idx] && idx <= s_quote_last)
//	{
//		if (idx != s_quote_last && idx != s_quote_frst)
//			write(1, &str[idx], 1);
//	}
//	while (str[idx])
//	{
//		if (str[idx] == '\'' && quote != '\"') 
//		{
//			print_quote_set(&str[idx], '\'', env_list);
//			return ;
//		}
//		else if (str[idx] == '\"' && quote != '\'') 
//		{
//			print_quote_set(&str[idx], '\"', env_list);	
//			return ;
//		}
//		else
//			write(1, &str[idx], 1);
//		idx++;
//	}
//}

static int	handle_line(char *line, t_list *env_list)
{
	int idx;

	idx = -1;
	while (line[++idx])
	{

		write(1, &line[idx], 1);
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
		handle_line(args[idx], env_list);
		if (args[idx + 1])
			write(1, " ", 1);
		idx++;
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (ret);
}
#if 0
//		if (ft_strchr(args[idx], '\''))
//			print_quote_set(args[idx], '\'', env_list);
//		else if (ft_strchr(args[idx], '\"'))
//			print_quote_set(args[idx], '\"', env_list);
//		else if (ft_strchr(args[idx], '$'))
//			print_with_val(args[idx], env_list);
		else
			write(1, args[idx], ft_strlen(args[idx]));
static int	sur_single_quote(char *str)
{
	int	s_quote_fst;
	int s_quote_scd;
	int std;
	int idx;

	s_quote_fst = 0;
	s_quote_scd = 0;
	std = 0;
	idx = -1;
	while (str[++idx])
	{
		if (str[idx] == '$')
			std = 1;
		else if (!std && (str[idx] == '\'') && s_quote_fst == 0)
			s_quote_fst = 1;
		else if (!std && (str[idx] == '\'') && s_quote_fst == 1)
			s_quote_fst = 0;
		else if (std && (str[idx] == '\'') && s_quote_scd == 0)
			s_quote_scd = 1;
		else if (std && (str[idx] == '\'') && s_quote_scd == 1)
			s_quote_scd = 0;
	}
	if (s_quote_fst && s_quote_scd)
		return (1);
	return (0);
}

static int	*init_q_flag(char **str)
{
	int	*flag;
	int len;
	int idx;

	len = -1;
	while (str[++len])
		;
	printf("%d\n", len);
	if (!(flag = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	idx = -1;
	while (++idx < len)
		flag[idx] = 0;
	return (flag);
}

#endif
