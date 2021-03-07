#include "../incs/minishell.h"
# define PATH_MAX 1024
static char *parse_arg(char *arg)
{
	char *parsed;
	
	//check single quote
	if ((ft_strchr(arg, '\'')))
	{
		printf("invalid single quote\n");
		return (NULL);
	}
	if (!(parsed = ft_strdup(arg)))
		return (NULL);
	if ((ft_strchr(arg, '\"') == 0)) 
		return (parsed);
	//check pair
	if (parsed[0] != '\"' || parsed[ft_strlen(arg) - 1] != '\"')
	{
		printf("invalid quote\n");
		free(parsed);
		return (NULL);
	}
	if (del_quote(&parsed))
	{
		printf("fail del quote\n");
		free(parsed);
		return (NULL);
	}
	if (ft_strchr(parsed, '\"')) 
	{
		printf("invalid quote\n");
		free(parsed);
		return (NULL);
	}
	return (parsed);
}

static char	*get_combined_path(char *arg, t_list *env_list)
{
	int		idx;
	int		len;
	char	*str;
	char	*path;

	idx = -1;
	while (arg[++idx] && arg[idx] != '$')
		;
	len = idx;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	idx = -1;
	while (++idx < len)
		str[idx] = arg[idx];
	path = get_eval(env_list, &arg[len + 1]);
	if (!(path = get_eval(env_list, &arg[len + 1])))
	{
		printf("cd: no such file or directory: %s\n", str);
		free(str);
		return (NULL);
	}
	path = ft_strjoin(str, path);
	free(str);
	return (path);
}

static char	*get_path(char **args, t_list *env_list)
{
	char	*path;
	char	*arg;

	//  is invalid arg, check quote
	path = NULL;
	if (!args[0])
		path = ft_strdup(get_eval(env_list, "HOME"));
	else if (args[1])
	{
		printf("cd: string not in pwd: %s\n", args[0]);
		return (NULL);
	}
	if (!(arg = parse_arg(args[0])))
		return (NULL);
	else if (ft_strchr(arg, '$'))
	{
		if (!(path = get_combined_path(arg, env_list)))
		{
			free(arg);
			return (NULL);
		}
	}
	else if (!(ft_strncmp(arg, "-", 1)))
		path = ft_strdup(get_eval(env_list, "OLDPWD"));
	else if (!(ft_strncmp(arg, "", ft_strlen(arg))))
		path = ft_strdup(get_eval(env_list, "PWD"));
	else
		path = ft_strdup(arg);
	free(arg);
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
	{
		if (chdir(path))
		{
			printf("cd: no such file or directory: %s\n", path);
			ret = 1;
		}
		free(path);
	}
	if (ret == 0)
	{
		tmp_list = get_elist(env_list, "OLDPWD");
		ret = mod_eval((t_env *)tmp_list->data, ft_strdup(old_pwd));
		tmp_list = get_elist(env_list, "PWD");
		ret = mod_eval((t_env *)tmp_list->data, ft_strdup(getcwd(cwd, PATH_MAX)));
	}
	return (ret);
}
