#include "../incs/minishell.h"

int		exit_shell(t_info *info)
{
	int ret;
	int i;

	ft_lstclear(&(info->line_list), &free);
	ft_lstclear(&(info->tokens_list), &free_tokens);
	ft_lstclear(&(info->env_list), &free_env);
	ft_lstclear(&(info->history), &free);
	if (info->env_list)
	{
		ft_lstclear(&(info->env_list), &free_env);
		free(info->env_list);
		info->env_list = NULL;
	}
	close_tokens_fds(info->tokens);
	exit(0);
	return (0);
}
