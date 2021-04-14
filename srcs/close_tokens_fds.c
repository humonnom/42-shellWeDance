#include "../incs/minishell.h"

void	close_tokens_fds(t_tokens *curr)
{
	int	range;
	int	idx;

	if (curr->fd_closed)
		return ;
	if (curr->type & (TYPE_REOUT_D | TYPE_REOUT))
		range = curr->fd_out_idx;
	if (curr->type & TYPE_REIN)
		range = curr->fd_in_idx;
	idx = -1;
	while (++idx < range)
	{
		if (curr->type & (TYPE_REOUT_D | TYPE_REOUT))
			close(curr->fd_out[idx]);
		if (curr->type & TYPE_REIN)
			close(curr->fd_in[idx]);
	}
	curr->fd_closed = 1;
}

