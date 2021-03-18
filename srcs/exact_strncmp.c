#include "../incs/minishell.h"

int	exact_strncmp(char *str1, char *str2)
{
	int	len;

	len = get_max_strlen(str1, str2);
	return (ft_strncmp(str1, str2, len));
}
