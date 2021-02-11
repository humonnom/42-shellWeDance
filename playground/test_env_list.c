#include "../minishell.h"

void			test_env_list(
				t_list *env_list)
{
	ps("======== TEST print sorted env ======\n");
	print_sorted_env(env_list);
}
