#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <unistd.h>

// head of data is cmd
typedef struct		s_env
{
	char			*key;
	char			*val;
}					t_env;

typedef struct		s_set
{
	char			**set;
	char			*cmd;
	char			**args;
}					t_set;

typedef struct		s_info
{
	t_list			*env_list;
	t_list			*set_list;
	t_set			*set;
    int     		exit;
    int     		ret;
}           		t_info;

#define BIT_SQUOTE 1
#define BIT_DQUOTE 2
#define ON 0x00001
#define OFF 0x00000
#define INF 987654321

/*
** handle_quote.c
*/
int				handle_quote(
				char *str,
				char **str_cpy,
				char c);

/*
** pk_split.c
*/
char			**pk_split(
				const char *s,
				const char *s_cpy,
				char c,
				int limit);

/*
** get_next_line.c
*/
int				get_next_line(char **line);

/*
** handle_bit.c
*/
int				turn_on_bit(
				int val,
				int n);
int				turn_off_bit(
				int val,
				int n);
int				check_bit(
				int val,
				int n);

/*
** init_minishell.c 
*/
int					init_minishell(
					t_info *info,
					char **env);

/*
** inc_shlvl.c
*/
int					inc_shlvl(t_list **env_head);

/*
** gen_elist
*/
t_list				*gen_elist(char **str);

/*
** get_elist.c
*/
t_list				*get_elist(
					t_list *list_head,
					char *tar);

/*
** get_eval.c
*/
char				*get_eval(
					t_list *list_head,
					char *tar);

int					mod_eval(
					t_env *env,
					char *new_val);

/*
** add_elist.c
*/
int					add_elist(
					t_list **list_head,
					char *key,
					char *val);

/*
** mod_elist.c
*/
int					mod_elist(
					t_list **list_head,
					char *key,
					char *val);

/*
** handle_list_index.c
*/
int					get_list_index(
					t_list *list_head,
					char *target);

/*
** print_list.c
*/
void				print_list(
					t_list *head);

/*
** print_set.c
*/
void				print_set(t_set *set);

/*
** print_slist.c
*/
void				print_slist(
					t_list *set_list);

/*
** print_elist.c
*/
void				print_elist(
					t_list *head);
/*
** sort_env.c
*/
void				print_sorted_env(t_list *env_list);

/*
** free_elist.c
*/
void				free_elist(t_list **list_head);

/*
** free_elist.c
*/
void				free_set(t_set *set);

/*
** parse_line.c
*/
t_list				*parse_line(char *line);

/*
** parse_set.c
*/
t_set				*parse_set(char *set_str);

/*
** get_env.c
*/
t_env				*get_env(char *set);

/*
** categorize_cmd.c
*/
int					categorize_cmd(t_info *info);

/*
** del_quote.c
*/
int					del_quote(char **str);

/*
** cvt_list_to_arr
*/
char				**cvt_list_to_arr(t_list *env_list);

/*
** print_darr
*/
void				print_darr(char **str);

/*
** free_darr
*/
char				**free_darr(char **tab, int limit);

/*
** select_sh_bti.c
*/
int					select_sh_bti(t_info *info);

/*
** run_bti.c
*/
int					run_bti(t_info *info);

/*
** export_env.c
*/
int					export_env(t_info *info, char *arg);

/*
** sh_bti_export.c
*/
int					sh_bti_export(char **args, t_list *env_list);

/*
** sh_bti_env.c
*/
int					sh_bti_env(t_list *env_list);

#endif

#if 0
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
#endif
