#include "../incs/minishell.h"

int ft_putchar_tc(int tc)
{
	write(STDOUT_FILENO, &tc, 1);
	return (0);
}

