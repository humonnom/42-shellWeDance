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
	int	status;

	pipe(fds);
	pid_t pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0) { // child process
		close(fds[0]);
		write(fds[1], DATA, DATA_LEN);
	}
	else { // parents process
		waitpid(pid, &status, 0);
		close(fds[1]);
		int read_size = read(fds[0], buf, DATA_LEN);
		for (int i = 0; i < read_size; ++i)
			write(STDOUT_FILENO, &buf[i], 1);
		close(fds[0]);
	}
	return (0);
}
