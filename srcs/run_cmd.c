#include "../incs/minishell.h"

int show_error(char const *str)
{
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	run_cmd(t_list *set_list, t_list *env_list)
{
	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;
	
	ret = EXIT_FAILURE;
	pipe_open = 0;

	t_set *curr = (t_set *)(set_list->data);
	t_set *prev;
	if (!(set_list->prev))
		prev = NULL;
	else
		prev = (t_set *)(set_list->prev->data);
	if (curr->type == TYPE_PIPE || (prev && prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(curr->fds))
			return (exit_fatal());	
	}

	pid = fork();
	if (pid < 0)
		return (exit_fatal());
	if (pid == 0)
	{
		if (curr->type == TYPE_PIPE 
			&& dup2(curr->fds[1], STDOUT_FILENO) < 0)
			return (exit_fatal());
		if (prev && prev->type == TYPE_PIPE
			&& dup2(prev->fds[0], STDIN_FILENO) < 0)
			return (exit_fatal());
		if ((ret = categorize_cmd(curr, env_list)) != 0)
		{
			show_error("error: cannot execute ");
			show_error(curr->cmd);
			show_error("\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(curr->fds[1]);
			if (curr->type == TYPE_BREAK)
				close(curr->fds[0]);
		}
		if (prev && prev->type == TYPE_PIPE)
			close(prev->fds[0]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}
