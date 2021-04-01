#include "../incs/minishell.h"

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
	info->set_list = NULL;
	info->set_str_list = NULL;
	info->env_list = NULL;
	info->exit = 0;
	info->ret = 0;
	info->history = NULL;
	info->tc = gen_tc();
}

//env_list has to be sort with printing.
int					init_minishell
					(t_info *info,
					char **env)
{
	int ret;

	ret = 0;
	
	init_info(info);
	if (ret == 0)
		if (!(info->env_list = gen_elist(env)))
			ret = 1;
	if (ret == 0)
		ret = inc_shlvl(&(info->env_list));
	//print_elist(info->env_list);
	return (ret);
}
