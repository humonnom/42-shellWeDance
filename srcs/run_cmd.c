/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:27 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:49:57 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

extern int	g_signal;

static void
	open_redir_fd(t_tokens *curr)
{
	if (curr->type & TYPE_REOUT)
		dup2(curr->fd_out[curr->fd_out_idx], STDOUT_FILENO);
	if (curr->type & TYPE_REOUT_D)
		dup2(curr->fd_out[curr->fd_out_idx], STDOUT_FILENO);
	if (curr->type & TYPE_REIN)
		dup2(curr->fd_in[curr->fd_in_idx], STDIN_FILENO);
}

static int
	close_fds(pid_t pid, t_tokens *curr, t_tokens *prev, int pipe_open)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_signal = WEXITSTATUS(status);
	if (pipe_open)
	{
		close(curr->fds[1]);
		if (curr->type & TYPE_BREAK)
			close(curr->fds[0]);
	}
	if (prev && (prev->type & TYPE_PIPE))
		close(prev->fds[0]);
	close_tokens_fds(curr);
	if (g_signal)
		return (1);
	return (0);
}

static int
	run_cmd_part(
	t_tokens *curr,
	t_tokens *prev,
	t_info *info,
	int pipe_open)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	handle_sig_in_proc(pid);
	if (pid < 0)
		return (sh_bti_exit(NULL, info, FLAG_PRINT_OFF));
	if (pid == 0)
	{
		if ((curr->type & TYPE_PIPE)
			&& dup2(curr->fds[1], STDOUT_FILENO) < 0)
			return (sh_bti_exit(NULL, info, FLAG_PRINT_OFF));
		if (prev && (prev->type & TYPE_PIPE)
			&& dup2(prev->fds[0], STDIN_FILENO) < 0)
			return (sh_bti_exit(NULL, info, FLAG_PRINT_OFF));
		open_redir_fd(curr);
		ret = categorize_cmd(curr, info);
		return (sh_bti_exit(NULL, info, FLAG_PRINT_OFF));
	}
	else
		ret = close_fds(pid, curr, prev, pipe_open);
	return (ret);
}

int
	run_cmd(t_info *info)
{
	int			ret;
	int			pipe_open;
	t_tokens	*curr;
	t_tokens	*prev;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	curr = (t_tokens *)(info->tokens_list->data);
	if (!(info->tokens_list->prev))
		prev = NULL;
	else
		prev = (t_tokens *)(info->tokens_list->prev->data);
	if ((curr->type & TYPE_PIPE) \
		|| (prev && (prev->type & TYPE_PIPE)))
	{
		pipe_open = 1;
		if (pipe(curr->fds))
			return (sh_bti_exit(NULL, info, FLAG_PRINT_OFF));
	}
	ret = run_cmd_part(curr, prev, info, pipe_open);
	if ((ret && (curr->type & TYPE_PIPE)) || (curr->type & TYPE_BREAK))
		ret = redo_sh_bti(info, curr, prev);
	return (ret);
}
