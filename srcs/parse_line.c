#include "minishell.h"

static int	change_semi2zero(char *src, char *src_cpy)
{
	// copy string for split_lines
	// duplicate and change semi colone to zero between dquotes
	return (0);
}	

static int		get_set_lst(
				t_lst *set_lst,
				char *line,
				char *set_cpy)
{
	int		ret;
	char 	**sets;
	char	*tmp_line;
	int		len;

	ret = 0;	
	if ((sets = split_sets(line, line_cpy, ';')) == 0)
		ret = 1;
	len = 0;
	while (ret == 0 && sets[len])
		len++;
	while (ret == 0 && sets[--len])
	{
		if ((tmp_line = ft_strdup(sets[len])) == NULL)
			ret = 1;
		ft_lstadd_front(&set_lst, ft_lstnew(tmp_line));
	}

	free_split(sets);
	return (ret);
}

// devide cmd, args set by ;
// return line_lst as linked_list form
int				parse_line(t_lst *set_lst)
{
	char *line;
	char *line_cpy;
	int	ret;

	ret = 0;
	if (ret == 0 && check_dquote(line, DQUOTE_OPEN))
		ret = 1;
	if (ret == 0 && change_semi2zero(line, line_cpy))
		ret = MALLOC_FAIL_ERR;
	if (ret == 0 && get_set_lst(set_lst, line, line_cpy))
		ret =  1;

	if (ret != MALLOC_FAIL)
		free (line_cpy);
	return (ret);
}

#if 0
$ echo "abc ; " ; cd ~ ;

1. line in gnl  : echo "abc ; " b c ; cd ~ 
2. line_cpy     : echo "abc 0 " b c ; cd ~ 
3. split_lines  : [echo "abc ; " b c, cd ~ ]
4. get_line_lst : {echo "abc"} -> {cd ~} 

#endif
