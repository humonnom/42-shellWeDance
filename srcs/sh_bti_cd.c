#include "../incs/minishell.h"
# define PATH_MAX 1024

static char	*handle_shortcut(char *arg, t_list *env_list)
{
	char	*ret;

	ret = arg;
	if (!ft_strlen(ret) || !exact_strncmp(ret, "~"))
	{
		free(ret);
		ret = ft_strdup(get_eval(env_list, "HOME"));
	}
	else if (!exact_strncmp(ret, "-"))
	{
		free(ret);
		ret = ft_strdup(get_eval(env_list, "OLDPWD"));
	}
	return (ret);
}

static char	*get_path(char *arg, t_list *env_list)
{
	char	*ret;
	char	*tmp_path;

	tmp_path = handle_arg(arg, env_list);
	ret = handle_shortcut(tmp_path, env_list);
	return (ret);
}

static int	renew_pwd(t_list *env_list)
{
	int		ret;
	t_list	*tmp_list;
	char	cwd[PATH_MAX];

	ret = 0;
	tmp_list = get_elist(env_list, "OLDPWD");
	ret = mod_eval((t_env *)tmp_list->data, get_eval(env_list, "PWD"));
	tmp_list = get_elist(env_list, "PWD");
	ret = mod_eval((t_env *)tmp_list->data, getcwd(cwd, PATH_MAX));
	return (ret);
}
	
int			sh_bti_cd(char **args, t_list *env_list)
{
	char	*path;
	int		ret;

	ret = 0;
	print_darr(args);
	if (args[0] && args[1])
	{
		printf("cd: string not in pwd: %s\n", args[0]);
		return (1);
	}
	if (!(path = get_path(args[0], env_list)))
		return (1);
	if (chdir(path) == -1)
	{
		printf("cd: no such file or directory: %s\n", path);
		ret = 1;
	}
	free(path);
	if (!ret)
		ret = renew_pwd(env_list);
	return (ret);
}
