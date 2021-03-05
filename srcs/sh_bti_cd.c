#include "../incs/minishell.h"
# define PATH_MAX 1024
static char	*get_path(char **args, t_list *env_list)
{
	char	*path;
	char	*tmp;

	path = NULL;
	if (!args[0])
		path = ft_strdup(get_eval(env_list, "HOME"));
	//  is invalid arg, check quote
	else if (!args[1])
	{
		printf("cd: string not in pwd: %s\n", args[0]);
		return (path);
	}
	else if (!(ft_strncmp(args[0], "$", 1)))
		path = ft_strdup(get_eval(env_list, &args[0][1]));
	else if (!(ft_strncmp(args[0], "-", 1)))
		path = ft_strdup(get_eval(env_list, "OLDPWD"));
	if (del_quote(&path))
		return (NULL);
	return (path);
}

int	sh_bti_cd(char **args, t_list *env_list)
{
	int		ret;
	char	*path;
	t_list	*tmp_list;
	char	cwd[PATH_MAX];
	char	*old_pwd;

	ret = 0;
	path = NULL;
	old_pwd = ft_strdup(get_eval(env_list, "PWD")); 
	if (!(path = get_path(args, env_list)))
		ret = 1;
	if (ret == 0 && path) 
	{	
		ret = chdir(path) ? 1 : 0;
		free(path);
	}
	if (ret == 0)
	{
		tmp_list = (get_elist(env_list, "OLDPWD"));
		ret = mod_eval((t_env *)tmp_list->data, ft_strdup(old_pwd));
		tmp_list = (get_elist(env_list, "PWD"));
		ret = mod_eval((t_env *)tmp_list->data, ft_strdup(getcwd(cwd, PATH_MAX)));
	}
	free(old_pwd);
	return (ret);
}
