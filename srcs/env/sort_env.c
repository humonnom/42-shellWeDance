#include "../../incs/minishell.h"

static int	has_to_change(char *s1, char*s2)
{
	int	s1_len;
	int	s2_len;
	int	max_len;
	
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	max_len = (s1_len > s2_len) ? s1_len : s2_len;
	return (ft_strncmp(s1, s2, max_len));
}

static int		get_str_len(
				char **str)
{
	int i;

	i = 0;
	while (str[i])
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
			if (has_to_change(env[i], env[i + 1]) > 0)
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

static char		*convert_list2str(
				t_list *list)
{
	t_list	*cur;
	char	*str;
	char	*tmp;

	cur = list;
	str = ft_strdup("");
	while (cur)
	{
		tmp = ft_strjoin(str, cur->data);
		free(str);
		str = ft_strjoin(tmp, "\n");
		free(tmp);
		cur = cur->next;
	}
	return (str);
}

void			print_sorted_env(
				t_list *env_list)
{
	char	*tmp;
	char	**str;
	int		i;

	tmp = convert_list2str(env_list);
	str = ft_split(tmp, '\n');
	str = sort_env(str, get_str_len(str) + 1);
	i = -1;
	while (str[++i])
	{
		printf("%s\n", str[i]);
		free(str[i]);
	}
	free(tmp);
	free(str);
}
