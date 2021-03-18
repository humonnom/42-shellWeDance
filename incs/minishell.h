#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/types.h>

# define TYPE_PIPE 1
# define TYPE_BREAK 2

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
	int				type;
	int				fds[2];
}					t_set;

typedef struct		s_info
{
	t_list			*env_list;
	t_list			*set_list;
	t_list			*set_str_list;
	t_set			*set;
    int     		exit;
    int     		ret;
	int				dollar_ret;
}           		t_info;

#define BIT_SQUOTE 1
#define BIT_DQUOTE 2
#define ON 0x00001
#define OFF 0x00000
#define INF 987654321
#define BUF_SIZE 1024

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
					t_list *head);

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
void				free_elist(t_list *list_head);

/*
** free_elist.c
*/
void				free_set(void *_set);

/*
** parse_line.c
*/
t_list				*parse_line(char *line);

/*
** get_set.c
*/
t_set				*get_set(char *set_str);

/*
** get_env.c
*/
t_env				*get_env(char *set);

/*
** free_env.c
*/
void				free_env(void *_env);

/*
** categorize_cmd.c
*/
int					categorize_cmd(
					t_set *set,
					t_list *env_list);

/*
** del_quote.c
*/
int					del_quote(char **str);

/*
** cvt_list_to_arr
*/
char				**set_list_to_darr(t_list *env_list);

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
int					select_sh_bti(
					t_set *set,
					t_list *env_list);

/*
** run_bti.c
*/
int					run_bti(
					t_set *set,
					t_list *env_list);

/*
** sh_bti_export.c
*/
int					sh_bti_export(	
					char **args,
					t_list *env_list);

int					sh_bti_unset(
					char **args,
					t_list *env_list);

/*
** sh_bti_env.c
*/
int					sh_bti_env(t_list *env_list);

/*
** sh_bti_pwd.c
*/
int					sh_bti_pwd(char **args);

/*
** sh_bti_echo.c
*/
int					sh_bti_echo(char **args, t_list *env_list);

/*
** get_max_strlen.c
*/
int					get_max_strlen(char *str1, char *str2);

/*
** get_dollar_eval.c
*/
char				*get_dollar_eval(
					char *part,
					t_list *env_list,
					int *idx);

/*
** sh_bti_echo.c
*/
int					sh_bti_echo(char **args, t_list *env_list);

/*
** sh_bti_cd.c
*/
int					sh_bti_cd(char **args, t_list *env_list);

/*
** cvt_char_to_str.c
*/
char				*cvt_char_to_str(char c);

/*
** is_squote.c
*/
int					is_squote(char c);

/*
** is_dquote.c
*/
int					is_dquote(char c);

/*
** handle_arg.c
*/
char				*handle_arg(
					char *arg,
					t_list *env_list);

/*
** exit_shell.c
*/
int					exit_shell(t_info *info);

/*
** exact_strncmp.c
*/
int					exact_strncmp(char *str1, char *str2);

/*
** get_list.c
*/
int					set_darr_to_list(
					t_list **list_head,
					char **str);
/*
** parse_set_list.c
*/
t_list				*parse_set(char *line);
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
