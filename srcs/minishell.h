#ifndef _MINISHELL_H
# define _MINISHELL_H

typedef struct		s_lst
{
	void			*data;
	struct s_lst	*next;
}					t_lst;

typedef struct  s_info
{
	t_lst		line_lst;
    int         exit;
    int         ret;
}               t_info;

#endif
