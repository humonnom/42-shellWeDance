#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "../libft/libft.h"
#include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

#if 1 
// head of data is cmd
typedef struct		s_slist
{
	t_list			*data;
	struct s_slist	*next;
}					t_slist;
#endif
typedef struct		s_set
{
	t_list			*args;
}					t_set;

typedef struct		s_env
{
	char			*key;
	char			*val;
}					t_env;

typedef struct		s_info
{
//	t_slist			*set_list;
	t_list			*env_list;
	t_list			*set_list;
    int     		exit;
    int     		ret;
}           		t_info;

#define BIT_SQUOTE 1
#define BIT_DQUOTE 2
#define ON 0x00001
#define OFF 0x00000
#define INF 987654321



int				handle_quote(
				char *str,
				char **str_cpy,
				char c);

char			**pk_split(
				const char *s,
				const char *s_cpy,
				char c,
				int limit);
void			pk_split_free(char **tab, int limit);

int				 get_next_line(char **line);


/*
** handle_bit.c
*/
int	turn_on_bit(int val, int n);
int	turn_off_bit(int val, int n);
int	check_bit(int val, int n);


/*
** init_minishell.c 
*/
int					init_minishell
					(t_info *info,
					char **env);

/*
** inc_shlvl.c
*/
int					inc_shlvl(t_list **env_head);

/*
** gen_elist
*/

int					gen_elist(
					t_list **list_head,
					char **str);

/*
** list/handle_list_life.c
*/
int					convert_str2list(
					t_list **list_head,
					char **str);

/*
** list/handle_list_data.c
*/

t_list			*get_elist(
				t_list *list_head,
				char *tar);

int				add_elist(
				t_list **list_head,
				char *key, char *val);

int				mod_elist(
				t_list **list_head,
				char *key, char *val);

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
					t_list *head);

/*
** list/print_elist.c
*/
void				print_elist(
					t_list *head);
/*
** env/sort_env.c
*/
void				print_sorted_env(t_list *env_list);

/*
** pk_lst.c
*/
void				pk_lstadd_front(
					t_slist **set_head,
					t_slist	*new_list);

t_slist				*pk_lstnew(
					void *data);

void				pk_lstdelone(
					t_slist *target,
					void (*del)(void *));
/*
** free_elist.c
*/
void				free_elist(t_list **list_head);

////////////==========================
#define MALLOC_FAIL 3
int				parse_line(char *line, t_slist **set_list);
int				parse_set(t_list **arg_list);
t_env			*parse_env(char *set);

int	get_list(
	t_list **list_head,
	char **str);
#endif
