#include "../incs/minishell.h"


#define TC_CURSOR_UP "\033[A"
#define TC_CURSOR_DOWN "\033[B"
#define TC_CURSOR_RIGHT "\033[C"
#define TC_CURSOR_LEFT "\033[D"
#define TC_ERASE_LINE "\033[1K"

int ft_cursor_mv_head(char *tc_str[], int row)
{
	char	*str;

	tputs(tgoto(tc_str[TC_CM], 0, row), 1, ft_putchar_tc);
	return (0);
}

int ft_cursor_mv_left(
	int	col,
	int	left_limit)
{
	char	*str;
	int		itr;

	str = "\033[D";
	if (col > left_limit + 1)
		write(STDIN_FILENO, str, ft_strlen(str));
	return (0);
}

int ft_cursor_mv_right(
	int	col,
	int	right_limit)
{
	char	*str;
	int		itr;

	str = "\033[C";
	if (col <= right_limit)
		write(STDIN_FILENO, str, ft_strlen(str));
	return (0);
}

int	ft_cursor_clr_line_all(char *tc_str[], int row)
{
	tputs(tc_str[TC_DL], 1, ft_putchar_tc);
	tputs(tgoto(tc_str[TC_CM], 0, row), 1, ft_putchar_tc);
	return (0);
}

int ft_cursor_clr_line_end(
	char *tc_str[],
	int col,
	int left_limit)
{

	if (col > left_limit + 1)
	{
		ft_putchar_fd('\b', STDOUT_FILENO);
		tputs(tc_str[TC_CE], 1, ft_putchar_tc);
	}
	return (0);
}
