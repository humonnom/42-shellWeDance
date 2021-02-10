#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	t_info info;

	init_minishell(&info, env);
	free_list(&(info.env_list));
	test_pk_lst();
}
//	test_env_list(info.env_list);
