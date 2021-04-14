#include "../incs/minishell.h"

void	close_tokens_fds(t_tokens *curr)
{
	int	range;
	int	idx;

	if (curr->type & (TYPE_REOUT_D | TYPE_REOUT))
		range = curr->fd_out_idx;
	if (curr->type & TYPE_REIN)
		range = curr->fd_in_idx;
	idx = -1;
	while (++idx < range && range < BUFFER_SIZE)
	{
		if ((curr->type & (TYPE_REOUT_D | TYPE_REOUT)) \
				&& curr->fd_out[idx] != -1)
		{
			close(curr->fd_out[idx]);
			curr->fd_out[idx] = -1;

		}
		if ((curr->type & TYPE_REIN) \
				&& curr->fd_in[idx] != -1)
		{
			close(curr->fd_in[idx]);
			curr->fd_in[idx] = -1;
		}
	}
}

