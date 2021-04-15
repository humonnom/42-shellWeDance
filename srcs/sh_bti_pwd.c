#include "../incs/minishell.h"

int	sh_bti_pwd(char **args)
{
	char s[BUFFER_SIZE];

	if (*args)
	{
		printf("%s\n", "pwd: too many arguments");
		return (1);
	}
	getcwd(s, BUFFER_SIZE);
	printf("%s\n", s);
	return 0;
}
