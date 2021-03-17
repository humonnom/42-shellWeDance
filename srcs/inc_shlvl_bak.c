#include "../incs/minishell.h"

int	inc_shlvl(t_list **env_head)
{
	t_list	*tmp_elist;
	t_env	*tmp_env;

	if (!(tmp_elist = get_elist(*env_head, "SHLVL")))
		return (1);
	tmp_env = (t_env *)(tmp_elist->data);
	if (mod_eval(tmp_env, ft_itoa(ft_atoi(tmp_env->val) + 1)))
		return (1);
	return (0);
}
