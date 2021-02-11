#include "../incs/minishell.h"

// malloc for original cmd(count size),
// remove " or '
static int trim_cmd(t_alist *arg_list)
{
    //1. check dquote open and pair
    //2. exclude dquote in arg_list head
    return (0);
}

// use strcmp for checking if word is cmd or not

static int get_arg_list(
    t_alist *arg_list,
    char *arg,
    char *arg_cpy)
{
    int ret;
    char **args;
    char *tmp_arg;
    int len;

    ret = 0;
    if ((args = pk_split(arg, arg_cpy, ' ')) == 0)
        ret = 1;
    len = 0;
    while (ret == 0 && args[len])
        len++;
    while (ret == 0 && args[--len])
    {
        if ((tmp_arg = ft_strdup(args[len])) == NULL)
            ret = 1;
        ft_lstadd_front(&arg_list, ft_listnew(tmp_arg));
        free(tmp_arg);
    }

    free_split(args);
    return (ret);
}
//arg_list->data : echo " a" char *arg = echo " a" char *arg_cpy = echo "0a" args = [echo, " a"]
//-> { echo " a" }

// line: single command and argument set
// word: [command, argument1, ...]
// in case that cmd = "ec""ho" ..
int parse_set(t_alist *arg_list)
{
    char *set;
    char *set_cpy;
    int ret;

    ret = 0;
    set = arg_list->data;
    ft_lstdelone(arg_list, &free);
    if (ret == 0 && dup_tmpstr(set, set_cpy, ' '))
        ret = MALLOC_FAIL_ERR;
    if (ret == 0 && get_arg_list(arg_list, set, set_cpy))
        ret = 1;
    if (ret == 0 && trim_cmd(arg_list))
        ret = 1;

    // devide cmd and argument
    // part of  "    "
    // arg1 arg2 ...

    return (ret);
}
