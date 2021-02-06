#ifndef _MINISHELL_H
# define _MINISHELL_H

// alist: argument list, head of data is cmd
typedef struct		s_alist
{
	void			*data;
	struct s_alist	*next;
}					t_alist;

// head of data is cmd
typedef struct		s_slist
{
	t_alist			*data;
	struct s_slst	*next;
}					t_slist;

typedef struct		s_info
{
	t_slist			*set_list;
    int     		exit;
    int     		ret;
}           		t_info;

#endif
