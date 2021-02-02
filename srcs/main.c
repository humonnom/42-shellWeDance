#include "minishell.h"

t_lst	*change_head(t_lst *line_lst)
{
	t_lst *ret;
	
	ret = line_lst->next;
	ft_lstdelone(line_lst, &free);
	return (ret); 
}

int		run(t_info *info)
{
    while(info->exit == ) 
	{
        init_sig();
		parse_input(info->line_lst);
		parse_line(info->line_lst);
		change_head(info->line_lst);
    }
}

int main(int argc, char *argv[], char *env[])
{
    t_info  info;

	init(info);
	if (run(&info))
		return (-1);
    free()
    return (info->ret)
}
