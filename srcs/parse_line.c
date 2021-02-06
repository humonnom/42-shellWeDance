#include "minishell.h"

static int		get_set_list(
				t_slist *set_list,
				char *set,
				char *set_cpy)
{
	int		ret;
	char 	**sets;
	char	*tmp_set;
	int		len;

	ret = 0;	
	if ((sets = pk_split(set, set_cpy, ';')) == 0)
		ret = 1;
	len = 0;
	while (ret == 0 && sets[len])
		len++;
	while (ret == 0 && sets[--len])
	{
		if ((tmp_set = ft_strdup(sets[len])) == NULL)
			ret = 1;
		pk_lstadd_front(&set_list, ft_lstnew(tmp_set));
		free(tmp_set);
	}

	free_split(sets);
	return (ret);
}

// devide cmd, args set by ;
// return line_list as linked_list form
int				parse_line(char *line, t_slist *set_list)
{
	char *line_cpy;
	int	ret;

	ret = 0;
	if (ret == 0 && check_dquote(line, DQUOTE_OPEN))
		ret = 1;
	if (ret == 0 && dup_tmpstr(line, line_cpy, ';'))
		ret = MALLOC_FAIL_ERR;
	if (ret == 0 && get_set_list(set_list, line, line_cpy))
		ret = 1;

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
