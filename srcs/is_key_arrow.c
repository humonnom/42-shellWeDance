#include "../incs/minishell.h"

int	is_key_arrow(long c)
{
	if (c == KEY_LEFT_ARROW)
		return (1);
	if (c == KEY_RIGHT_ARROW)
		return (1);
	if (c == KEY_UP_ARROW)
		return (1);
	if (c == KEY_DOWN_ARROW)
		return (1);
	return (0);
}
