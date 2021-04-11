#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char	c;
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
	while (read(STDIN_FILENO, &c, sizeof(c)) > 0) {
		printf("keycode: %c\n", c);
	}
#if 0
	while (read(STDIN_FILENO, &d, sizeof(d)) > 0) {
		printf("keycode: %ld\n", d);
	}
#endif
	return (0);	
}
