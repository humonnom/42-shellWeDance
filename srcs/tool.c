#include "minishell.h"

int	dup_tmpstr(char *src, char *src_cpy, char target)
{
    // copy string for split_lines
    // duplicate and change target to zero between dquotes

    return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	s1_len;
	int	s2_len;
	
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return (ft_strncmp(s1, s2, ((s1_len > s2_len) ? s1_len : s2_len)));
}

void	print_env(t_list *env_list)
{
	t_list *now;

	now = env_list;
	while (now)
	{
		ps(now->content);
		now = now->next;
	}
}
