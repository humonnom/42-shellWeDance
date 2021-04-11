#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct termios old_settings;

int main()
{
	struct termios new_settings;

	int vdisable;
	char buf[255];
#if 0
	if ((vdisable = fpathconf(0, _PC_VDISABLE)) < 0) {
		perror("error ");
		exit(0);
	}
	printf("vdisable: %d\n", vdisable);
#endif

	tcgetattr(0, &new_settings);
	old_settings = new_settings;
	new_settings.c_cc[VEOF] = 255;
	tcsetattr(0, TCSAFLUSH, &new_settings);
	memset(buf, 0x00, 255);
	read(0, buf, 255);
	printf("%s\n", buf);
	tcsetattr(0, TCSAFLUSH, &old_settings);
	exit(0);
	return (0);
}
