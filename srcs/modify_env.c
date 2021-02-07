#include "minishell.h"

char*	get_env_value(t_list **env_head, char *target)
{
	t_list	*cur;

	cur = *env_head;
	while (cur)
	{
		if (!!(ft_strnstr(cur->content, target, ft_strlen(target))))
			return (ft_strchr(cur->content, '=') + 1);
		cur = cur->next; 
	}
	return (0);
}

int		add_env(t_list **env_head, char *key, char*value)
{
	char	*new;

	key = ft_strjoin(key, "=");
	new = ft_strjoin(key, value);
	ft_lstadd_front(env_head, ft_lstnew(new));
	free(key);
	return (0);
}

int		del_env(t_list **env_head, char *target)
{
	t_list *cur;
	t_list *next;

	cur = *env_head;
	if (ft_strncmp(cur->content, target, ft_strlen(target)) == 0)
	{
		*env_head = cur->next;
		ft_lstdelone(cur, &free);
		return (0);
	}
	while (cur->next)
	{
		next = cur->next;
		if (ft_strncmp(next->content, target, ft_strlen(target)) == 0)
		{
			cur->next = next->next;
			ft_lstdelone(next, &free);
			return (0);
		}
		cur = next;
	}
	return (1);
}

int		mod_env(t_list **env_head, char *key, char *value)
{
	int ret;

	ret = 0;
	if (ret == 0)
		ret = del_env(env_head, key);
	if (ret == 0)
		ret = add_env(env_head, key, value);
	print_sorted_env(*env_head);
	return (ret);
}
