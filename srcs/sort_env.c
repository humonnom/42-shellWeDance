#include "minishell.h"

static int		get_env_len(
				char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

static char**	sort_env(
				char **env,
				int env_len)
{
	int		i;
	int		sorted_flag;
	char	*tmp;

	sorted_flag = 1;
	while (--env_len && sorted_flag)
	{
		i = -1;
		sorted_flag = 0;
		while (++i < env_len - 1)
		{
			if (ft_strcmp(env[i], env[i + 1]) > 0)
			{	
				tmp = env[i];
				env[i] = env[i + 1];
				env[i + 1] = tmp;
				sorted_flag = 1;
			}
		}
	}
	return (env);
}

static char		*env_list_2str(
				t_list *env_list)
{
	t_list	*cur;
	char	*str;

	cur = env_list;
	str = ft_strdup("");
	while (cur)
	{
		str = ft_strjoin(str, cur->content);
		str = ft_strjoin(str, "\n");
		cur = cur->next;
	}
	return (str);
}

void			print_sorted_env(
				t_list *env_list)
{
	char	**str;
	int		i;

	str = ft_split(env_list_2str(env_list), '\n');
	str = sort_env(str, get_env_len(str) + 1);
	i = -1;
	while (str[++i])
		ps(str[i]);
	free(str);
}
