#include "../incs/minishell.h"

// malloc for original cmd(count size),
// remove " or '
#if 0
static int trim_cmd(t_alist *arg_list)
{
    //1. check dquote open and pair
    //2. exclude dquote in arg_list head
    return (0);
}
#endif

// use strcmp for checking if word is cmd or not

//arg_list->data : echo " a" char *arg = echo " a" char *arg_cpy = echo "0a" args = [echo, " a"]
//-> { echo " a" }

// line: single command and argument set
// word: [command, argument1, ...]
// in case that cmd = "ec""ho" ..
int parse_set(t_list **arg_list)
{
    char	*set;
    char	*set_cpy;
	char	**arg_part;
    int		ret;

    ret = 0;
	set = (*arg_list)->data;
	free(*arg_list);
	*arg_list = NULL;
    if (ret == 0 && !(set_cpy = ft_strdup(set)))
		ret = 1;
	if (ret == 0 && handle_quote(set, &set_cpy, ' '))
		ret = 1;
	if (ret == 0 && !(arg_part = pk_split(set, set_cpy, ' ')))
		ret = 1;
    if (ret == 0 && get_list(arg_list, arg_part))
        ret = 1;
	free(set_cpy);

#if 0
    if (ret == 0 && trim_cmd(arg_list))
        ret = 1;
#endif


    // devide cmd and argument
    // part of  "    "
    // arg1 arg2 ...

    return (ret);
}
