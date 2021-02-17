#include "minishell.h"

int	handle_cmd_pwd()
{
	printf("%s\n", pwd);
	return 0;
}
