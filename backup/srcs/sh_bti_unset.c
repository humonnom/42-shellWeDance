#include "../incs/minishell.h"

static int	cmp_key(t_list *env_list, char *key2)
{
	t_env	*tmp_env;
	char	*key;

	tmp_env = (t_env *)(env_list->data);
	key = tmp_env->key;
	return (exact_strncmp(key, key2));
}

static void	del_elist_if(
			t_list **env_list,
			char *key)
{
	t_list	*prev;
	t_list	*next;
	t_list	*tmp;

	while (*env_list && !cmp_key(*env_list, key))
	{
		tmp = *env_list;
		*env_list = (*env_list)->next;
		free_elist(tmp);
	}
	prev = *env_list;
	while (prev && prev->next)
	{
		next = prev->next;
		if (!cmp_key(next, key))
		{
			tmp = next;
			prev->next = next->next;
			free_elist(tmp);
		}
		else
			prev = next;
	}
}

int	sh_bti_unset(
	char **args,
	t_list **env_list)
{
	int		idx;

	if (!args)
		return (1);
	idx = -1;
	while (args[++idx])
		del_elist_if(env_list, args[idx]);
	return (0);
}
