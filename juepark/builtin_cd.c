#include "minishell.h"
static char	*get_path(char *dest, char *pwd, t_list *env_list)
{
	char	*path;
	char	*tmp;

	path = NULL;
	if ((ft_strncmp(dest, "..", ft_strlen(dest)) == 0))
		path = ft_strdup("..");
	else if ((ft_strncmp(dest, "~", ft_strlen(dest)) == 0))
	{
		tmp = ft_strdup(get_list_data(env_list, "HOME"));
		path = ft_strdup(&tmp[5]);
		free(tmp);
	}
	else
		path = ft_strdup(dest);
	return (path);
}

static int	renew_old_pwd(char **old_one, char *new_one)
{
	free(*old_one);
	*old_one = ft_strdup(&(new_one[4]));
	return 0;
}

static int	go_path(char *dest, t_list *env_list, char **old_pwd)
{
	char	*path;
	char	*pwd;
	int		ret;
	char	s[100];

	ret = 0;
	path = NULL;
	if (ft_strncmp(dest, "-", ft_strlen(dest)) == 0)
	{
		if (*old_pwd)
			path = getcwd(s, 100);
		if (ret == 0)
			path = ft_strdup(*old_pwd);
	}
	else
	{
		if (!(pwd = get_list_data(env_list, "PWD")))
			ret = 1;
		if (ret == 0 && !(path = get_path(dest, pwd, env_list)))
			ret = 1;
		if (ret == 0 && (renew_old_pwd(old_pwd, pwd)))
			ret = 1;
	}
	if (ret == 0 && path)
	{
		ret = chdir(path) ? 1 : 0;
		if (ret == 0 && modify_list_data(&env_list, "PWD", getcwd(s, 100)))
			ret = 1;
	}
	return (ret);
}

int	handle_cmd_cd(t_list *arg_list, t_list *env_list, char **old_pwd)
{
	int		ret;
	t_list	*arg;

	ret = 0;
	arg = arg_list;
	while (arg->next)
	{
		arg = arg->next;
		go_path(arg->data, env_list, old_pwd);
	}
	if (arg == arg_list)
		go_path("~", env_list, old_pwd);
	return ret;
}

