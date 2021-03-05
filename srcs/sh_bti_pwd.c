#include "../incs/minishell.h"
# define PATH_MAX 1024
int	sh_bti_pwd()
{
	char s[PATH_MAX];

	printf("%s\n", getcwd(s, PATH_MAX));
	return 0;
}
