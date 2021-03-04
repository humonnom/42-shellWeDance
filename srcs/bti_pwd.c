#include "minishell.h"

int	handle_cmd_pwd(void)
{
	char s[100];

	printf("%s\n", getcwd(s, 100));
	return 0;
}
