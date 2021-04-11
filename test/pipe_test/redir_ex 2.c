#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define TYPE_PIPE 1
#define TYPE_BREAK 2

typedef struct		s_set
{
	char			*args[30];
	int				fds[2];
	int				type;
	struct s_set	*next;
	struct s_set	*prev;
}					t_tokens;

#if 0
void	add_args(char **args, char **buf) {
	int i;
	i = 1;
	while (buf[i - 1])
	{
		args[i] = buf[i - 1];
		++i;
	}
	args[i] = NULL;
}
#endif

int run(t_tokens *tokens, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	if (tokens->type == TYPE_PIPE || (tokens->prev && tokens->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		// both set1 and set2 use pipe function to connect fds[0], fds[1]
		pipe(tokens->fds);
	}
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		printf("child process========================\n");
		// fds[1] of set1 has result of ls -al
		if (tokens->type == TYPE_PIPE)
			dup2(tokens->fds[1], STDOUT_FILENO);
		// fds[0] of set1 has input of ls -al for grep
		if (tokens->prev && (tokens->prev->type == TYPE_PIPE))
			dup2(tokens->prev->fds[0], STDIN_FILENO);
		if ((ret = execve(tokens->args[0], tokens->args, env) < 0))
			exit(0); 
		printf("child process finished===============\n");
	}
	else
	{
		printf("parent process=======================\n");
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			// close fds[1] of set1 
			// close fds[1] of set2
			close(tokens->fds[1]);
			// fds[0] of set1 is still open
			if (!tokens->next || tokens->type == TYPE_BREAK)
				// fds[0] of set2 is closed
				close(tokens->fds[0]);
		}
		if (tokens->prev && tokens->prev->type == TYPE_PIPE)
			// fds[0] of set1 is closed
			close(tokens->prev->fds[0]);
		printf("parent process finished==============\n");
	}
	return (ret);
}

int main(int argc, char *argv[], char *env[]) {
	t_tokens	set1;
	set1.args[0] = "/bin/ls";
	set1.args[1] = "-al";
	set1.args[2] = NULL;
	set1.type = TYPE_PIPE;

	t_tokens	set2;
	set2.args[0] = "/usr/bin/grep";
	set2.args[1] = "main";
	set2.args[2] = NULL;
	set2.type = TYPE_BREAK;

	set1.prev = NULL;
	set1.next = &set2;
	set2.prev = &set1;
	set2.next = NULL;
	printf("first run\n");
	run(&set1, env);
	printf("second run\n");
	run(&set2, env);
	return (0);
}

#if 0
int run1(t_tokens *tokens, char **env)
{
	pipe(tokens->fds);
	pid_t pid;
	int	status;

	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		printf("child process========================\n");
		print_tokens(tokens);
		dup2(tokens->fds[0], STDOUT_FILENO);
		if (execve(tokens->args[0], tokens->args, env) < 0)
			exit(0); 
	}
	else
	{
		printf("parent process=======================\n");
		waitpid(pid, &status, 0);
		close(tokens->fds[1]);
	}
	return (0);
}

int run2(t_tokens *tokens, char **env)
{
	pipe(tokens->fds);
	pid_t pid;
	int	status;

	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		printf("child process========================\n");
		print_tokens(tokens);
		dup2(tokens->fds[1], STDIN_FILENO);
		if (execve(tokens->args[0], tokens->args, env) < 0)
			exit(0); 
	}
	else
	{
		printf("parent process=======================\n");
		waitpid(pid, &status, 0);
		close(tokens->fds[0]);
	}
	return (0);
}
#endif
