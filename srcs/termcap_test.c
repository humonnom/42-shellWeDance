#include "../incs/minishell.h"

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

static t_tc	gen_tc()
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

int test()
{
	t_tc	tc;
	
	tc = gen_tc();
	char *prompt = ">> ";
	long	inst_arr[1024];

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
		ft_memset(inst_arr, 0, 1024);
		int	k = -1;
		while ((read(0, &c, sizeof(c)) > 0) && (c != '\n'))
		{
			if (c <= KEY_LEFT_ARROW)
				inst_arr[++k] = c;
			get_cursor_pos(&tc.cursor.col, &tc.cursor.row);
			//printf("col: %d, row: %d\n", tc.cursor.col, tc.cursor.row);
			if (ft_isprint(c))
			{
				ft_putchar_fd(c, 1);
				char *tmp = cvt_char_to_str(c);
				str_in = ft_strjoin(str_in, tmp);
				++buf_len;
			}
			else if (c == KEY_LEFT_ARROW)
				ft_cursor_mv_left(tc.cursor.col, prompt_len);
			else if (c == KEY_RIGHT_ARROW)
				ft_cursor_mv_right(tc.cursor.col, prompt_len + buf_len);
			else if (c == KEY_UP_ARROW)
			{
				ft_cursor_clr_line_all(tc.tc_str, tc.cursor.row);
				ft_cursor_mv_head(tc.tc_str, tc.cursor.row);
				write(1, prompt, ft_strlen(prompt));
				ft_putstr_fd("NEW LINE==============", 1);
			}
			else if (c == KEY_BACKSPACE)
				ft_cursor_clr_line_end(tc.tc_str);
			c = 0;
		}
		printf("\nstr_in: %s\n", str_in);
		printf("inst list===============================\n");
		for (int i = 0; i < k; ++i)
			printf("inst_arr[%d]: %ld\n", i, inst_arr[i]);
	}
	return (0);	
}
