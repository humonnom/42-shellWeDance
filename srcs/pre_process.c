#include "../incs/minishell.h"

int					inc_shell_level(t_list **env_head)
{
	char	*value;
	char	*data;
	int		level;
	int		ret;

	ret = (!(data = get_list_data(*env_head, "SHLVL")));
	if (ret == 0)
		ret = (!(level = ft_atoi(&data[6])));
	if (ret == 0)
		ret = (!(value = ft_itoa(level + 1)));
	if (ret == 0)
		modify_list_data(env_head, "SHLVL", value);
	if (ret == 0)
		free(value);
	return (ret);
}

int					process_pre(
					t_list **env_head,
					char **env)
{
	int		ret;
	char	*value;

	get_list(env_head, env);
	ret = inc_shell_level(env_head);
	return (ret);
}
