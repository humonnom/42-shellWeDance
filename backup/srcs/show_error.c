#include "../incs/minishell.h"

int show_error(char const *str)
{
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	return (EXIT_FAILURE);
}
