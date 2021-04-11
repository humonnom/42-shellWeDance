#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA "Hello World!\n"
#define DATA_LEN 13

int main() {
    int fds[2];
    char buf[1024];
    int status;

    pipe(fds);
	printf("DEBUG=========================\n");
	dup2(fds[1], STDOUT_FILENO);
	write(STDOUT_FILENO, DATA, DATA_LEN);
	int read_size = read(fds[0], buf, DATA_LEN);
	for (int i = 0; i < read_size; ++i)
		write(STDOUT_FILENO, &buf[i], 1);
    return (0);
}
