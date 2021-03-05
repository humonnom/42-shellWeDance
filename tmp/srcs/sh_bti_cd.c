#include "../incs/minishell.h"
# define PATH_MAX 1024
static int	is_invalid_arg(char	*arg)
{
	int	ret;

	ret = 0;
	if ((ft_strchr(arg, '\"') == 0)) 
		return (0);
	if ((ft_strchr(arg, "\'")))
		return (1);
	//check pair
	//check space
	if (ret === 0 && del_quote(&path))
		ret = 1;
	return (ret);
}

static char	*get_path(char **args, t_list *env_list)
{
	char	*path;
	char	*tmp;

	//  is invalid arg, check quote
	path = NULL;
	if (!args[0])
		path = get_eval(env_list, "HOME");
	else if (args[1])
	{
		printf("cd: string not in pwd: %s\n", args[0]);
		return (path);
	}
	if (is_invalid_arg(args[0]))
		return (NULL);
	else if (!(ft_strncmp(args[0], "$", 1)))
		path = get_eval(env_list, &args[0][1]);
	else if (!(ft_strncmp(args[0], "-", 1)))
		path = get_eval(env_list, "OLDPWD");
	else
		path = args[0];
//	if (del_quote(&path))
//		return (NULL);
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
	old_pwd = get_eval(env_list, "PWD"); 
	if (!(path = get_path(args, env_list)))
		ret = 1;
	if (ret == 0 && path) 
		ret = chdir(path) ? 1 : 0;
	if (ret == 0)
	{
		tmp_list = get_elist(env_list, "OLDPWD");
		ret = mod_eval((t_env *)tmp_list->data, ft_strdup(old_pwd));
		tmp_list = get_elist(env_list, "PWD");
		ret = mod_eval((t_env *)tmp_list->data, ft_strdup(getcwd(cwd, PATH_MAX)));
	}
	return (ret);
}
