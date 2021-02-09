#ifndef _MINISHELL_H
# define _MINISHELL_H

# include "libft/libft.h"

// head of data is cmd
typedef struct		s_slist
{
	t_list			*data;
	struct s_slist	*next;
}					t_slist;

typedef struct		s_info
{
	t_slist			*set_list;
    int     		exit;
    int     		ret;
}           		t_info;


#define BIT_SQUOTE 1
#define BIT_DQUOTE 2
#define ON 0x00001
#define OFF 0x00000



int				handle_quote(
				char *str,
				char **str_cpy,
				char c);

char			**pk_split(
				const char *s,
				const char *s_cpy,
				char c);

int				 get_next_line(char **line);


/*
** handle_bit.c
*/
int	turn_on_bit(int val, int n);
int	turn_off_bit(int val, int n);
int	check_bit(int val, int n);

#endif
