#include "../incs/minishell.h"

char	handle_enter(
		int backup_len,
		char buf,
		int read_size)
{
	int ret;

	ret = 0;
	if((backup_len == 0) && buf == '\n' && read_size == 1)
	{
		display_prompt();
		ret = 1;
	}
	return (ret);
}
