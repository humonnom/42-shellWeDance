#include "../incs/minishell.h"

#include <stdio.h>

#define BACKSPACE 127
#define LEFT_ARROW 4479771
#define RIGHT_ARROW 4414235
#define UP_ARROW 4283163
#define DOWN_ARROW 4348699

typedef struct		s_cursor
{
	int				row;
	int				col;
}					t_cursor;

typedef struct		s_tc
{
	struct	termios	term;
	char			*tc_str[3];
	t_cursor		cursor;
}					t_tc;

int			inst_list[BUF_SIZE];

static void get_cursor_pos(int *col, int *row)
{
	int		cnt;
	int		idx;
	char	buf[255];
	int		read_size;

	write(STDIN_FILENO, "\033[6n", ft_strlen("\033[6n"));
	read_size = read(STDIN_FILENO, buf, 255); 
	buf[read_size] = '\0';
	idx = -1;
	while (!ft_isdigit(buf[idx]))
		++idx;
	*row = 0;
	while (ft_isdigit(buf[idx]))
		*row = *row * 10 + buf[idx++] - '0'; 
	++idx;
	*col = 0;
	while (ft_isdigit(buf[idx]))
		*col = *col * 10 + buf[idx++] - '0'; 
}

t_tc	gen_tc()
{
	t_tc	ret;

	tcgetattr(STDIN_FILENO, &(ret.term));
	ret.term.c_lflag &= ~ICANON;
	ret.term.c_lflag &= ~ECHO;
	ret.term.c_cc[VMIN] = 1;
	ret.term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &(ret.term));

	ret.cursor.row = 0;
	ret.cursor.col = 0;

	tgetent(NULL, "xterm");
	ret.tc_str[TC_CM] = tgetstr("cm", NULL); 
	ret.tc_str[TC_DL] = tgetstr("dl", NULL); 
	ret.tc_str[TC_CE] = tgetstr("ce", NULL); 

	return (ret);
}

#if 1
int test()
{
	t_tc	tc;
	
	tc = gen_tc();
	char *prompt = ">> ";

	long c;
	while (1)
	{
		c = 0;
		get_cursor_pos(&tc.cursor.col, &tc.cursor.row);
		ft_cursor_mv_head(tc.tc_str, tc.cursor.row);
		write(1, prompt, ft_strlen(prompt));
		char *str_in = ft_strdup("");
		int prompt_len = ft_strlen(prompt);
		int buf_len = 0;
		while ((read(0, &c, sizeof(c)) > 0) && (c != '\n'))
		{
			get_cursor_pos(&tc.cursor.col, &tc.cursor.row);
			//printf("col: %d, row: %d\n", tc.cursor.col, tc.cursor.row);
			if (ft_isprint(c))
			{
				ft_putchar_fd(c, 1);
				char *tmp = cvt_char_to_str(c);
				str_in = ft_strjoin(str_in, tmp);
				++buf_len;
			}
			else if (c == LEFT_ARROW)
				ft_cursor_mv_left(tc.cursor.col, prompt_len);
			else if (c == RIGHT_ARROW)
				ft_cursor_mv_right(tc.cursor.col, prompt_len + buf_len);
			else if (c == UP_ARROW)
			{
				ft_cursor_clr_line_all(tc.tc_str, tc.cursor.row);
				break ;
			}
			else if (c == BACKSPACE)
				ft_cursor_clr_line_end(tc.tc_str);
			c = 0;
		}
		printf("\nstr_in: %s\n", str_in);
	}
	return (0);	
}
#endif
