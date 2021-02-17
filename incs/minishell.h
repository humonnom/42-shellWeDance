#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "../libft/libft.h"
#include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// head of data is cmd
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
void			pk_split_free(char **tab);

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
** pre_process.c
*/
int					process_pre(
					t_list **env_head,
					char **env);

int					inc_shell_level(t_list **env_head);

/*
** list/handle_list_life.c
*/
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

int					add_list_data(
					t_list **list_head,
					char *key, char *value);

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
** free_list.c
*/
void				free_list(t_list **list_head);

////////////==========================
#define MALLOC_FAIL 3
int				parse_line(char *line, t_slist **set_list);
int				parse_set(t_list **arg_list);
int				export_env(t_list **list_head, char *set);

int	get_list(
	t_list **list_head,
	char **str);
#endif
