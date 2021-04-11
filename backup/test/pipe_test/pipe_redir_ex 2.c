#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define TYPE_PIPE 1
#define TYPE_BREAK 2
#define TYPE_REIN 4
#define TYPE_REOUT 8

typedef struct		s_set
{
	char			*args[30];
	int				fds[2];
	int				type;
	int				fd[2];
	struct s_set	*next;
	struct s_set	*prev;
}					t_tokens;

int run(t_tokens *tokens, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	if ((tokens->type & TYPE_PIPE) || (tokens->prev && (tokens->prev->type & TYPE_PIPE)))
	{
		pipe_open = 1;
		pipe(tokens->fds);
	}
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		if (tokens->type & TYPE_PIPE)
			dup2(tokens->fds[1], STDOUT_FILENO);
////////////////////////////////////////////////////////////////////////////////
		if (tokens->type & TYPE_REIN)
			dup2(tokens->fd[0], STDIN_FILENO);
		if (tokens->type & TYPE_REIN)
			dup2(tokens->fd[1], STDIN_FILENO);
		if (tokens->type & TYPE_REOUT)
			dup2(tokens->fd[0], STDOUT_FILENO);
////////////////////////////////////////////////////////////////////////////////
		if (tokens->prev && (tokens->prev->type & TYPE_PIPE))
			dup2(tokens->prev->fds[0], STDIN_FILENO);
		if ((ret = execve(tokens->args[0], tokens->args, env) < 0))
			exit(0); 
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(tokens->fds[1]);
			if (!tokens->next || (tokens->type & TYPE_BREAK))
				close(tokens->fds[0]);
		}
		if (tokens->prev && (tokens->prev->type & TYPE_PIPE))
			close(tokens->prev->fds[0]);
#if 1
		if (tokens->type & TYPE_REIN)
			close(tokens->fd[0]);
		if (tokens->type & TYPE_REIN)
			close(tokens->fd[1]);
		if (tokens->type & TYPE_REOUT)
			close(tokens->fd[0]);
#endif
	}
	return (ret);
}

int main(int argc, char *argv[], char *env[]) {
	t_tokens	set1;
	set1.args[0] = "/usr/bin/sort";
	set1.args[1] = NULL;
	set1.type = TYPE_BREAK | TYPE_REIN;
	set1.fd[0] = open("test.txt", O_RDONLY);
	set1.fd[1] = open("test2.txt", O_RDONLY);

#if 0
	t_tokens	set2;
	set2.args[0] = "/usr/bin/grep";
	set2.args[1] = "a";
	set2.args[2] = NULL;
	set2.type = TYPE_BREAK | TYPE_REOUT;
	set2.fd = open("test2.txt", O_CREAT | O_APPEND | O_WRONLY, 0755);

	set1.prev = NULL;
	set1.next = &set2;
	set2.prev = &set1;
	set2.next = NULL;
	run(&set1, env);
	run(&set2, env);
#endif
	run(&set1, env);

	return (0);
}
