typedef struct		s_alist
{
	void			*data;
	struct s_alist	*next;
}					t_alist;

static int	check_dquote_open(char *line)
{
	// add single quote case
	// ", ' check pair
	int	open;
	int	ret;

	while (*line)
	{
		++line;
	}
	
	return (0);
}

#if 0
static int trim_cmd(t_alist *arg_list)
{
    //1. check dquote open and pair
    //2. exclude dquote in arg_lst head
    return (0);
}
#endif

#include <stdio.h>
int main(int argc, char **argv) {
	printf("input: %s\n", argv[1]);
	//check_dquote_open("asdfadsfasdfsadfasdf");


}
