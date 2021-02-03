#include "minishell.h"


// malloc for original cmd(count size), 
// remove " or ' 
static int	trim_cmd(char **cmd)
{
	
	return (0);
}

// use strcmp for checking if word is cmd or not
static int	check_cmd(char *word)
{
	return (0);
}

// line: single command and argument set 
// word: [command, argument1, ...]
// in case that cmd = "ec""ho" ..
int	parse_cmd_args(t_lst *line)
{
	int		ret;
	char	**words;

	ret = 0;
	words = ft_split(line, ' ');
	if (ret == 0 && trim_cmd(&words[0]))
		ret = 1;
	if (ret == 0 && check_cmd(words[0]))
		ret = 1;

	// devide cmd and argument
	// part of  "    "
	// arg1 arg2 ...

	

	free_split(words);
	return (ret);	
}
