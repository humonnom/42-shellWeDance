#include "../incs/minishell.h"
# define PATH_MAX 1024
int	sh_bti_pwd(char **args)
{
	char s[PATH_MAX];

	if (*args)
	{
		printf("%s\n", "pwd: too many arguments");
		return (1);
	}
	printf("%s\n", getcwd(s, PATH_MAX));
	return 0;
}
