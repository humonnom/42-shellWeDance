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

t_list
	*sort_elist(t_list *env_list)
{
	char		*str1;
	char		*str2;
	t_list		*begin;
	t_list		*cur;

	begin = env_list;
//	while (begin->next)
//	{
//		cur = begin;
//		while (cur->next)
//		{
//			str1 = cvt_env_to_str((t_env *)cur->data);
//			str2 = cvt_env_to_str((t_env *)cur->next->data);
////			if (exact_strncmp(str1, str2))
////			{
////				cur->data = str2;
////				cur->next->data = str1;
////			}
//			cur = cur->next;
//		}
//		begin = begin->next;
//	}
	return (env_list);
}
