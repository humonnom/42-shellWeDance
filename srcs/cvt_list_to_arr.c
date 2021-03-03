#include "../incs/minishell.h"

char	**cvt_list_to_arr(t_list *env_list)
{
	char	**ret;
	int		idx;
	int		list_size;
	t_env	*tmp_env;

	list_size = ft_lstsize(env_list);
	if (!(ret = (char **)malloc(sizeof(char *) * (list_size + 1))))
		return (0);
	idx = 0;
	while (env_list)
	{
		tmp_env = (t_env *)(env_list->data);
		ret[idx] = ft_strjoin(tmp_env->key, "=");
		ret[idx] = ft_strjoin(ret[idx], tmp_env->val);
		if (!ret[idx])
		{
			printf("ERROR: strdup error in convert_list_to_arr\n");
			return (free_darr(ret, idx));
		}
		++idx;
		env_list = env_list->next;
	}
	return (ret);
}
