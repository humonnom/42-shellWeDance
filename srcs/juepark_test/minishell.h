#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>

# define pf(X) printf(""#X" :%f\n", X)
# define pd(X) printf(""#X" :%d\n", X)
# define px(X) printf(""#X" :%x\n", X)
# define ps(X) printf("%s\n", X)

typedef struct		s_slist
{
	t_list			*data;
	struct s_slist	*next;
}					t_slist;

typedef struct		s_info
{
	t_slist			*set_list;
	t_list			*env_list;
    int     		exit;
    int     		ret;
}           		t_info;

/*
** init_minishell.c 
*/
int					init_minishell
					(t_info *info,
					char **env);

/*
** pre_process.c
*/
int					process_pre(
					t_list **env_head,
					char **env);

int					inc_shell_level(t_list **env_head);

/*
** list/handle_list_life.c
*/
void				free_list(
					t_list **list_head);

int					convert_str2list(
					t_list **list_head,
					char **str);

/*
** list/handle_list_data.c
*/

int					modify_list_data(
					t_list **list_head,
					char *key,
					char *value);

char				*get_list_data(
					t_list *list_head,
					char *target);

/*
** list/handle_list_index.c
*/

int					get_list_index(
					t_list *list_head,
					char *target);

/*
** list/print_list.c
*/
void				print_list(
					t_list **head);

/*
** env/sort_env.c
*/
void				print_sorted_env(t_list *env_list);

/*
** pk_lst.c
*/
void				pk_lstadd_front(
					t_slist **set_head,
					t_slist	*new);

t_slist				*pk_lstnew(
					void *data);

void				pk_lstdelone(
					t_slist *target,
					void (*del)(void *));

/*
** test_list.c
*/
void				test_pk_lst();
void				test_env_list();

#endif
