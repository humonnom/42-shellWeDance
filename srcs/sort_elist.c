#include "../incs/minishell.h"

static char
	*cvt_env_to_str(t_env *env)
{
	char	*ret;
	char	*tmp;

	ret = ft_strjoin(env->key, "=");
	tmp = ft_strjoin(ret, env->val);
	free(ret);
	ret = tmp;
	return (ret);
}

static int
	swap_str(t_list *cur, t_list *next)
{
	char		*cur_str;
	char		*next_str;
	t_env		*tmp_env;

	cur_str = cvt_env_to_str(cur->data);
	next_str = cvt_env_to_str(next->data);
	if (exact_strncmp(cur_str, next_str) > 0)
	{
		tmp_env = cur->data;
		cur->data = next->data;
		next->data = tmp_env; 
		return (1);
	}
	return (0);
}

t_list
	*sort_elist(t_list *env_list)
{
	t_list		*begin;
	t_list		*cur;
	t_list		*next;
	int			swaped;

	char		*cur_str;
	char		*next_str;

	begin = env_list;
	swaped = 1;
	while (begin->next && swaped)
	{
		swaped = 0;
		cur = begin;
		while (cur->next)
		{
			next = cur->next;
			swaped = swap_str(cur, cur->next);
			cur = cur->next;
		}
		begin = begin->next;
	}
	print_elist(env_list);
	return (env_list);
}
