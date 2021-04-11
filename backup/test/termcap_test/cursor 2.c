#include <termcap.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

#define LEFT_ARROW 4479771
#define RIGHT_ARROW 4414235

int ft_putchar_tc(int tc)
{
	write(STDOUT_FILENO, &tc, 1);
	return (0);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

void get_cursor_pos(int *row, int *col)
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

void move_cursor_left()
{
	write(STDIN_FILENO, "\033[D", 4);
}

void move_cursor_right()
{
	write(STDIN_FILENO, "\033[C", 4);
}

int main()
{
	long	d;
	struct	termios term;
#if 1
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
#endif
#if 0
	while (read(STDIN_FILENO, &c, sizeof(c)) > 0) {
		printf("keycode: %c\n", c);
	}
#endif
#if 1
	int col;
	int row;
	char *prompt;

	long c;
	prompt = ">> ";
	while (1)
	{
		write(1, prompt, ft_strlen(prompt));
		c = 0;
		while (read(0, &c, sizeof(c)) > 0)
		{
			//printf("keycode: %ld\n", c);
			if (c == '\n')
			{
				printf("DEBUG=========================\n");
				break ;
			}
			get_cursor_pos(&row, &col);
			if (col > 3 && c == LEFT_ARROW)
				write(STDIN_FILENO, "\033[D", ft_strlen("\033[D"));
			else if (c == RIGHT_ARROW)
				write(STDIN_FILENO, "\033[C", ft_strlen("\033[C"));
			else 
				write(1, &c, 1);
		}
	}
#endif
#if 0
	while (read(STDIN_FILENO, &d, sizeof(d)) > 0) {
		printf("keycode: %ld\n", d);
	}
#endif
	return (0);	
}
