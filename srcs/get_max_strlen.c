#include "../incs/minishell.h"

int	get_max_strlen(char *str1, char *str2)
{
	int	str1_len;
	int	str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	if (str1_len < str2_len)
		return (str2_len);
	return (str1_len);
}
