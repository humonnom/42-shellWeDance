#include "../incs/minishell.h"

int			run_bti(t_set *set, t_list *env_list)
{
	char	*func_path;
	char	**cand_arr;
	int		idx;
	char	*bti_path;
	char	**env_arr;

	if (!(func_path = get_eval(env_list, "PATH")))
		printf("ERROR: func_path is NULL\n");
	cand_arr = pk_split(func_path, func_path, ':', INF);
	idx = -1;
	bti_path = NULL;
	while (cand_arr[++idx])
	{
		if ((bti_path = get_bti_path(cand_arr[idx], set->cmd)))
			break ;
	}
	free_darr(cand_arr, INF);
	if (!bti_path)
		return (1);
	env_arr = set_list_to_darr(env_list);
	if (execve(bti_path, set->set, env_arr) < 0)
		return (1);
	free(bti_path);
	free_darr(env_arr, INF);
	return (0);
}
