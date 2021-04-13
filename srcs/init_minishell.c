#include "../incs/minishell.h"

extern int	g_signal;

static t_tc	gen_tc()
{
	t_tc	ret;

	tcgetattr(STDIN_FILENO, &(ret.term));
	ret.term.c_lflag &= ~ICANON;
	ret.term.c_lflag &= ~ECHO;
	ret.term.c_cc[VMIN] = 1;
	ret.term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &(ret.term));

	ret.cursor.row = 0;
	ret.cursor.col = 0;

	tgetent(NULL, "xterm");
	ret.tc_str[TC_CM] = tgetstr("cm", NULL); 
	ret.tc_str[TC_DL] = tgetstr("dl", NULL); 
	ret.tc_str[TC_CE] = tgetstr("ce", NULL); 
	return (ret);
}

static void			init_info(
					t_info *info)
{
	info->prompt.data = ">> ";//shell💃we🕺dance===> 
	info->prompt.size = ft_strlen(info->prompt.data);
	info->tokens_list = NULL;
	info->line_list = NULL;
	info->env_list = NULL;
	info->exit = 0;
	info->ret = 0;
	info->history = NULL;
	ft_lstadd_front(&(info->history), ft_lstnew(ft_strdup("")));
	ft_lstadd_front(&(info->history), ft_lstnew(ft_strdup("")));
	info->history_ptr = info->history;
	info->tc = gen_tc();
}

//env_list has to be sort with printing.
int					init_minishell
					(t_info *info,
					char **env)
{
	int ret;

	ret = 0;

	g_signal = OFF;	
	init_info(info);
	if (ret == 0)
		if (!(info->env_list = gen_elist(env)))
			ret = 1;
	if (ret == 0)
		ret = inc_shlvl(&(info->env_list));
	return (ret);
}
