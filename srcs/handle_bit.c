#include "../incs/minishell.h"

int	turn_on_bit(int val, int n)
{
	return (val |= (1 << n));
}

int	turn_off_bit(int val, int n)
{
	return (val &= ~(1 << n));
}

int	check_bit(int val, int n)
{
	if ((val >> n) & ON)
		return (ON);
	return (OFF);
}

