#include "../incs/minishell.h"

static void	turn_on_echo(t_info *info)
{
	info->tc.term.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &(info->tc.term));
}

int categorize_cmd(t_tokens *tokens, t_info *info)
{
	int		ret;
	int		run_check;
	int		idx;

	ret = 1;
	run_check = 0;
	if (del_quote(&(tokens->cmd)))
	{
		printf("ERROR: trim_cmd malloc error\n");
		return (1);
	}
	ret = select_sh_bti(tokens, info);
	if (ret) 
	{
		turn_on_echo(info);
		ret = run_bti(tokens, info->env_list);
	}
	if (ret)
		printf("command not found: %s\n", tokens->cmd);
	return (ret);
}
