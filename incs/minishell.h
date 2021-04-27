/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:22:07 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:59:36 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <termcap.h>
# include <termios.h>
# include <signal.h>
# include <curses.h>

# define TYPE_PIPE 1
# define TYPE_BREAK 2
# define TYPE_REIN 4
# define TYPE_REOUT 8
# define TYPE_REOUT_D 16
# define TYPE_ERROR 32

# define KEY_BACKSPACE_KEY 127
# define KEY_LEFT_ARROW 4479771
# define KEY_RIGHT_ARROW 4414235
# define KEY_UP_ARROW 4283163
# define KEY_DOWN_ARROW 4348699
# define KEY_EOF 4

# define TC_CM 0
# define TC_DL 1
# define TC_CE 2

# define BUFFER_SIZE 1024

# define RET_INIT 0
# define RET_FAIL 1
# define RET_SIGINT 130
# define RET_SIGQUIT 131
# define SIG_SIGINT -1
# define SIG_SIGQUIT -2

# define ERR_MALLOC 1
# define ERR_SH_BTI 2
# define ERR_BTI 4
# define ERR_NOT_FOUND 404

# define FLAG_PRINT_ON 1
# define FLAG_PRINT_OFF 0
# define RESULT_EXPORT_PRINT 1
# define RESULT_EXPORT_INVALID 2

# define OPEN 1
# define CLOSE 0

# define PROMPT_DATA ">> "
# define PROMPT_SIZE 3

# define TC_CURSOR_UP "\033[A"
# define TC_CURSOR_DOWN "\033[B"
# define TC_CURSOR_RIGHT "\033[C"
# define TC_CURSOR_LEFT "\033[D"
# define TC_ERASE_LINE "\033[1K"

# define BIT_SQUOTE 1
# define BIT_DQUOTE 2
# define ON 0x00001
# define OFF 0x00000
# define INF 987654321
# define BUF_SIZE 1024

typedef struct		s_env
{
	char			*key;
	char			*val;
}					t_env;

typedef struct		s_cursor
{
	int				row;
	int				col;
}					t_cursor;

typedef struct		s_tc
{
	struct termios	term;
	char			*tc_str[3];
	int				limit;
	t_cursor		cursor;
}					t_tc;

typedef struct		s_tokens
{
	char			**tokens;
	char			*cmd;
	char			**args;
	int				type;
	int				fds[2];
	int				fd_in_idx;
	int				fd_in[1024];
	int				fd_out_idx;
	int				fd_out[1024];
}					t_tokens;

typedef struct		s_info
{
	t_list			*env_list;
	t_list			*tokens_list;
	t_list			*line_list;
	t_list			*history;
	t_list			*history_ptr;
	t_tokens		*tokens;
	int				exit;
	int				ret;
	int				inst_buf[1024];
	t_tc			tc;
}					t_info;

/*
** handle_quote.c
*/
int					handle_quote(
					char *str,
					char **str_cpy,
					char c);

/*
** pk_split.c
*/
char				**pk_split(
					const char *s,
					const char *s_cpy,
					char c,
					int limit);

/*
** handle_bit.c
*/
int					turn_on_bit(
					int val,
					int n);
int					turn_off_bit(
					int val,
					int n);
int					check_bit(
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
int					inc_shlvl(
					t_list **env_head);

/*
** gen_elist
*/
t_list				*gen_elist(
					char **str);

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
** sort_elist.c
*/
t_list				*sort_elist(
					t_list *env_list);

/*
** print_list.c
*/
void				print_list(
					t_list *head);

/*
** print_tokens.c
*/
void				print_tokens(
					t_tokens *tokens);

/*
** print_elist.c
*/
void				print_elist(
					t_list *head);

/*
** print_sorted_elist.c
*/
int					print_sorted_elist(
					t_list *head);

/*
** free_elist.c
*/
void				free_elist(
					t_list *list_head);

/*
** free_elist.c
*/
void				free_tokens(
					void *tokens_tmp);

/*
** gen_line_list.c
*/
t_list				*gen_line_list(
					char *lines);

/*
** gen_tokens.c
*/
t_tokens			*gen_tokens(
					char *line);

/*
** gen_env.c
*/
t_env				*gen_env(char *tokens);

/*
** free_env.c
*/
void				free_env(void *env_tmp);

/*
** categorize_cmd.c
*/
int					categorize_cmd(
					t_tokens *tokens,
					t_info *info);

/*
** del_quote.c
*/
int					del_quote(char **str);

/*
** cvt_list_to_arr
*/
char				**set_list_to_darr(
					t_list *env_list);

/*
** free_darr
*/
char				**free_darr(char **tab, int limit);

/*
** select_sh_bti.c
*/
int					select_sh_bti(
					t_tokens *tokens,
					t_info *info);

/*
** run_bti.c
*/
int					run_bti(
					t_tokens *tokens,
					t_list *env_list);

/*
** sh_bti_export.c
*/
int					sh_bti_export(
					char **args,
					t_list **env_list,
					int flag_print);

/*
** sh_bti_export_utils.c
*/
int					is_invalid_key(
					t_env *env,
					int flag_print);

int					is_digit_in_key_head(
					t_env *env,
					int flag_print);

int					is_equal_in_str(
					char *str);

int					is_empty_str(
					char *str);

/*
** sh_bti_unset.c
*/
int					sh_bti_unset(
					char **args,
					t_list **env_list,
					int flag_print);

/*
** sh_bti_env.c
*/
int					sh_bti_env(
					t_list *env_list);

/*
** sh_bti_pwd.c
*/
int					sh_bti_pwd();

/*
** sh_bti_echo.c
*/
int					sh_bti_echo(
					char **args,
					t_list *env_list);

/*
** sh_bti_exit.c
*/
int					sh_bti_exit(
					char **args,
					t_info *info,
					int flag_print);

/*
** get_max_strlen.c
*/
int					get_max_strlen(
					char *str1,
					char *str2);

/*
** get_dollar_eval.c
*/
char				*get_dollar_eval(
					char *part,
					t_list *env_list,
					int *idx);

/*
** sh_bti_cd.c
*/
int					sh_bti_cd(
					char **args,
					t_list *env_list,
					int flag_print);

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
** gen_tokens_list.c
*/
t_list				*gen_tokens_list(t_info *info);

/*
** run_cmd.c
*/
int					run_cmd(
					t_info *info);

/*
** show_error.c
*/
int					show_error(char const *str);

/*
** redo_sh_bti.c
*/
int					redo_sh_bti(
					t_info *info,
					t_tokens *token,
					t_tokens *prev);

/*
** set_bracet_type.c
*/
int					set_bracket_type(
					char *str,
					int *idx);

/*
** set_fd.c
*/
char				*set_fd(
					t_tokens *tokens,
					char *line);

/*
** set_fd_info.c
*/
int					set_fd_info(
					t_tokens *tokens,
					char *str,
					int curr_type);
/*
** is_bracket.c
*/
int					is_bracket(char c);

/*
** is_valid_fd.c
*/
int					is_valid_fd(
					t_tokens *tokens,
					char *str,
					int *idx,
					int type);

/*
** open_valid_fd.c
*/
int					open_valid_fd(
					t_tokens *tokens,
					char *set_str,
					int *idx,
					int type);

int					ft_putchar_tc(
					int tc);

/*
** ft_cursor.c
*/
void				ft_cursor_clr_line_end_loop(
					t_info *info,
					int left_limit);

int					ft_cursor_clr_line_end(
					t_tc *tc,
					int left_limit);

int					ft_cursor_mv_head(
					t_tc *tc,
					int use_col_pos_flag);

int					ft_cursor_clr_line_all(
					t_tc *tc);

char				*get_next_line_tc(
					t_info *info);

int					is_key_arrow(
					long c);

/*
** get_cursor_pos.c
*/
void				get_cursor_pos(
					int *col,
					int *row);

/*
** append_history_list.c
*/
void				append_history_list(
					t_list **history,
					char *line);

/*
** calc.c
*/
int					calc_min(
					int num1,
					int num2);

int					calc_max(
					int num1,
					int num2);

int					set_signo();

void				handle_sig_in_proc();

void				handle_eof_in_gnl(
					t_info *info,
					long *c,
					int buf_len);

void				handle_sig_in_gnl(
					t_info *info,
					long *arr,
					int *idx,
					int *buf_len);

int					handle_key_arrow(
					t_info *info,
					long arr[],
					long c,
					int right_limit);

void				close_tokens_fds(
					t_tokens *curr);

int					is_exist_dir(
					char *dir_path);

char				*handle_back_slash(
					char *str,
					char c);

#endif
