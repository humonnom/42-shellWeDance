#include "minishell.h"

void	init_env(
		t_info *info,
		char **env)
{
	int i;

	i = 0;
	while (env[++i])
		ft_lstadd_front(&(info->env_list), ft_lstnew(ft_strdup(env[i])));
}

void	free_env(
		t_list **env_head)
{
	t_list *cur;
	t_list *tmp;

	cur = *env_head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		ft_lstdelone(tmp, &free);
	}
	env_head = NULL;
}
