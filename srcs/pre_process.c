#include "minishell.h"

void	inc_shell_level(t_list **env_head)
{
	char	*cur;
	int		level;

	cur = get_env_value(env_head, "SHLVL");
	level = ft_atoi(cur);
	mod_env(env_head, "SHLVL", ft_itoa(level + 1));
	return ;
}

// find specific env, return index
int		process_pre(t_info *info, char **env)
{
	int		ret;
	char	*value;

	ret = 0;
	init_env(info, env);
	inc_shell_level(&(info->env_list));
	return (ret);
}

