
typedef struct  s_info
{
	t_lst		line_lst;
    int         exit
    int         ret
}               t_info;

void	process_pre(t_info info)
{
    init_env();
    inc_shell_level();
}

int		get_lines(t_info *info, char *line)
{
	char 	**lines;
	int		len;

	if ((lines = ft_split(line, ';')) == 0)
		return -1;
	len = 0;
	while (lines[len++])
		;
	while (lines[len])
	{
		ft_lstadd_front(line_lst, ft_lstnew(lines[len]);
		len--;
	}
}

int		parse_input(t_info *info)
{
	char *line;

	if (info->line_lst == NULL)
	{
		if ((get_next_line(&line)) == -1)
			return -1;
		if (get_lines(info, line) == -1)
			return -1;
	}
	return 0;
}


int		run(t_info info)
{
    while(info->exit == ) 
	{
        init_sig();
		parse_input();
    }
}

void	init_info(t_info *info)
{
	info->line_lst = 0;
}

int main(int argc, char *argv[], char *env[])
{
    t_info  info;

	init_info(&info);
	process_pre(info);
	if (run(info))
		return (-1);
    free()
    return (info->ret)
}
