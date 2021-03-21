#include "../incs/minishell.h"

void	show_cmd_error(char *cmd)
{
   show_error("error: cannot execute ");
   show_error(cmd);
   show_error("\n");
}

static int	close_fds(pid_t pid, t_set *curr, t_set *prev, int pipe_open)
{
	int	status;
	int	ret;
	
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
	return (ret);
}

static int	run_cmd_part(
			t_set *curr,
			t_set *prev,
			t_info *info,
			int pipe_open)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	handle_sig_proc(pid);
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
		if ((ret = categorize_cmd(curr, info)) != 0)
			show_cmd_error(curr->cmd);
		// test about sh_bti_exit case
		exit(ret);
	}
	else
		ret = close_fds(pid, curr, prev, pipe_open);
	return (ret);
}

int	run_cmd(t_info *info)
{
	int		ret;
	int		status;
	int		pipe_open;
	t_set	*curr;
    t_set	*prev;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	curr = (t_set *)(info->set_list->data);
	if (!(info->set_list->prev))
		prev = NULL;
	else
		prev = (t_set *)(info->set_list->prev->data);
	if (curr->type == TYPE_PIPE || (prev && prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(curr->fds))
			return (exit_fatal());	
	}
	ret = run_cmd_part(curr, prev, info, pipe_open);
	if (ret != EXIT_FAILURE && curr->type == TYPE_BREAK)
		ret = redo_sh_bti(curr, info);
	return (ret);
}