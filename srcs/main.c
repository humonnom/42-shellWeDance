
typedef struct  s_info
{
	t_lst		line_lst;
    int         exit
    int         ret
}               t_info;

void	process_pre(t_info *info)
{
    init_env(info);
    inc_shell_level(info);
}

int		get_lines(t_info *info, char *line)
{
	char 	**lines;
	char	*tmp_line;
	int		len;

	if ((lines = split_lines(line, ';')) == 0)
		return -1;
	len = 0;
	while (lines[len])
		len++;
	while (lines[--len])
	{
		tmp_line = ft_strdup(lines[len]);
		ft_lstadd_front(line_lst, ft_lstnew(tmp_line));
	}
	free_ft_split(lines);
}

int		parse_input(t_info *info)
{
	char *line;

	if (info->line_lst == NULL)
	{
		if ((get_next_line(&line)) == -1)
			return -1;
		check_dquote();
		if (get_lines(info, line) == -1)
			return -1;
	}
	return 0;
}

t_lst	*change_head(t_lst *line_lst)
{
	t_lst *ret;
	
	ret = line_lst->next;
	ft_lstdelone(line_lst, &free);
	return (ret); 
}

int		check_dquote(line)
{
	check_dquote_open();
	
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

void	init_info(t_info *info)
{
	info->line_lst = 0;
}

int main(int argc, char *argv[], char *env[])
{
    t_info  info;

	init_info(&info);
	process_pre(&info);
	if (run(&info))
		return (-1);
    free()
    return (info->ret)
}
