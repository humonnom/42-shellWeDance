#include "../incs/minishell.h"
# define PATH_MAX 1024

static char	*get_var_name(char *arg)
{
	char	*var_name;
	char	*arg_delq;

	var_name = NULL;
	arg_delq = ft_strdup(arg); 
	if (del_quote(&arg_delq))
		return (NULL);
	if (!arg || !(ft_strncmp(arg_delq, "~", ft_strlen(arg_delq))))
		var_name = ft_strdup("HOME");
	else if (!(ft_strncmp(arg_delq, "-", ft_strlen(arg_delq))))
		var_name = ft_strdup("OLDPWD");
	else if (!(ft_strncmp(arg_delq, "", ft_strlen(arg_delq))))
		var_name = ft_strdup("");
	free(arg_delq);
	return (var_name);
}

static char	*get_path(char *arg, t_list *env_list)
{
	char	*path;
	char	*var_name;

	var_name = get_var_name(arg);
	if (var_name)
	{
		if (ft_strncmp(var_name, "", ft_strlen(var_name)))
			path = ft_strdup("");
		else if (!(path = ft_strdup(get_eval(env_list, var_name))))
			path = ft_strdup(get_eval(env_list, "HOME"));
		free(var_name);
	}
	else if (ft_strchr(arg, '$'))
	{
		path = get_part(arg, env_list);
		printf("($)path : %s\n", path);
	}
	else
		path = ft_strdup(arg);
	return (path);
}
static int	renew_pwd(char *old_pwd, t_list *env_list)
{
	int		ret;
	t_list	*tmp_list;
	char	cwd[PATH_MAX];

	ret = 0;
	tmp_list = get_elist(env_list, "OLDPWD");
	ret = mod_eval((t_env *)tmp_list->data, ft_strdup(old_pwd));
	tmp_list = get_elist(env_list, "PWD");
	ret = mod_eval((t_env *)tmp_list->data, ft_strdup(getcwd(cwd, PATH_MAX)));
	return (ret);
}
	
int			sh_bti_cd(char **args, t_list *env_list)
{
	char	*path;
	char	*old_pwd;
	int		ret;

	ret = 0;
	if (args[1])
	{
		printf("cd: string not in pwd: %s\n", args[0]);
		return (1);
	}
	if (!(path = get_path(args[0], env_list)))
		return (1);
	old_pwd = get_eval(env_list, "PWD"); 
	if (ft_strncmp(path, "", ft_strlen(path)) && chdir(path) == -1)
	{
		printf("cd: no such file or directory: %s\n", path);
		ret = 1;
	}
	free(path);
	if (!ret)
		ret = renew_pwd(old_pwd, env_list);
	return (ret);
}
