#ifndef _MINISHELL_H
# define _MINISHELL_H

// alst: argument list, head of data is cmd
typedef struct		s_alst
{
	void			*data;
	struct s_alst	*next;
}					t_alst;

// head of data is cmd
typedef struct		s_slst
{
	t_alst			*data;
	struct s_slst	*next;
}					t_slst;

typedef struct		s_info
{
	t_slst			*set_lst;
    int     		exit;
    int     		ret;
}           		t_info;

#endif
