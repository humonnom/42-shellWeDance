#include "../incs/minishell.h"

int	calc_min(int num1, int num2)
{
	if (num1 > num2)
		return (num2);
	return (num1);
}

int	calc_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
