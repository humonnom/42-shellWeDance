#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "libft/libft.h"
# include "init.h"
# include <stdio.h>

# define pf(X) printf(""#X" :%f\n", X)
# define pd(X) printf(""#X" :%d\n", X)
# define ps(X) printf("%s\n", X)

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
	struct s_slist	*next;
}					t_slist;

typedef struct		s_info
{
	t_slist			*set_list;
	t_list			*env_list;
    int     		exit;
    int     		ret;
}           		t_info;

/* init_minishell */
void				init_minishell(t_info *info, char **env);
static void			init_info(t_info *info);

/* pre_process */
int					process_pre(t_info *info, char **env);
void				inc_shell_level(t_list **env_head);

/* init_env */
void				init_env(t_info *info, char **env);
void				free_env(t_list **env_head);

/* modify_env */
int					add_env(t_list **env_head, char *key, char *value);
int					del_env(t_list **env_head, char *target);
int					mod_env(t_list **env_head, char *key, char *value);
char				*get_env_value(t_list **env_head, char *target);

/* sort_env */
void				print_sorted_env(t_list *env_list);
static char			**sort_env(char **env, int env_len);
static char			*env_list_2str(t_list *env_list);
static int			get_env_len(char **env);

/* pk_lst */
void				pk_lstadd_front(t_slist **set_head, void *content);

/* tool */
void				print_env(t_list *env_list);
int					ft_strcmp(char *s1, char *s2);
#endif
