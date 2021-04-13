#include "../incs/minishell.h"

int	inc_shlvl(t_list **env_head)
{
	t_list	*tmp_elist;
	t_env	*tmp_env;
	char	*new_val;

	if (!(tmp_elist = get_elist(*env_head, "SHLVL")))
		return (1);
	tmp_env = (t_env *)(tmp_elist->data);
	new_val = ft_itoa(ft_atoi(tmp_env->val) + 1);
	if (mod_eval(tmp_env, new_val))
		return (1);
	free(new_val);
	new_val = NULL;
	return (0);
}
