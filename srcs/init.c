#include "minishell.h"

static void	process_pre(t_info *info)
{
    init_env(info);
    inc_shell_level(info);
}

static void	init_info(t_info *info)
{
	info->line_lst = 0;
}

void		init(t_info *info) {
	init_info(info);
	process_pre(info);


}
