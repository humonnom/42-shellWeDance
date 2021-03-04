#include "minishell.h"
# define PATH_MAX 1024

static char	*get_path(char *dest, t_list *env_list, char **old_pwd)
{
	char	*path;
	char	*tmp;

	path = NULL;
	if ((ft_strncmp(dest, "-", ft_strlen(dest)) == 0))
		path = *old_pwd ? ft_strdup(*old_pwd) : 0;
	else if ((ft_strncmp(dest, "..", ft_strlen(dest)) == 0))
		path = ft_strdup("..");
	else if ((ft_strncmp(dest, "~", ft_strlen(dest)) == 0))
		path = ft_strdup(get_list_value(env_list, "HOME"));
	else
		path = ft_strdup(dest);
	return (path);
}

static int	renew_old_pwd(char **old_one, char *new_one)
{
	free(*old_one);
	if (!(*old_one = ft_strdup(new_one)))
		return (1);
	return (0);
}

static int	move_to_path(char *dest, t_list *env_list, char **old_pwd)
{
	char	*path;
	int		ret;
	char	cwd[PATH_MAX];

	ret = 0;
	path = get_path(dest, env_list, old_pwd);
	if (path)
	{
		ret = renew_old_pwd(old_pwd, getcwd(cwd, PATH_MAX));
		if (ret == 0)
			ret = chdir(path) ? 1 : 0;
		if (ret == 0)
			ret = modify_list_data(&env_list, "PWD", getcwd(cwd, PATH_MAX));
		free(path);
	}
	return (ret);
}

int	handle_cmd_cd(t_list *arg_list, t_list *env_list, char **old_pwd)
{
	int		ret;
	t_list	*arg;

	ret = 0;
	arg = arg_list;
	while (ret == 0 && arg->next)
	{
		arg = arg->next;
		printf("while :%s\n", arg->data);
		ret = move_to_path(arg->data, env_list, old_pwd);
	}
	if (ret == 0 && arg == arg_list)
		ret = move_to_path("~", env_list, old_pwd);
	return (ret);
}

	// case:						mine	zsh		cc
	// {../}			 			 ✅		✅		❌
	// {..}				 			 ✅		✅		❌	
	// {..;}			 			 ✅		✅		❌
	// {cd} {..}		 			 ✅		✅		✅

	// {cd} {../}		 			 ✅		✅		✅
	// {cd} {../../}	 			 ✅		✅		✅
	// {cd} {../} {../}				 ✅		❌		⚠️ (cd ../)

	// {cd} {..;..;}	   			 		✅		❌
	// {cd} {..;} {..;}	   			 		✅		❌
	
	// {cd} {~}						✅		✅		❌
	// {cd} {~/Documents}  			❌		✅		❌
	// {cd} {~;} {Documents}		❌		✅		❌
	// {cd} {~} {Documents}			✅		✅		❌




