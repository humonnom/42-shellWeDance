/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bti_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:20:57 by juepark           #+#    #+#             */
/*   Updated: 2021/04/27 14:51:53 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

#define ERR_CD_ALLOC_FAIL 2
#define ERR_CD_CHDIR 1

extern int g_signal;

static char
	*handle_shortcut(
	char *arg,
	t_list *env_list)
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

static char
	*get_path(
	char *arg,
	t_list *env_list)
{
	char	*ret;
	char	*tmp_path;

	tmp_path = handle_arg(arg, env_list);
	ret = handle_shortcut(tmp_path, env_list);
	return (ret);
}

static int
	renew_pwd(
	t_list *env_list)
{
	t_list	*tmp_list;
	char	*tmp_pwd;
	char	cwd[BUFFER_SIZE];
	int		ret;

	ret = 0;
	tmp_list = get_elist(env_list, "OLDPWD");
	tmp_pwd = get_eval(env_list, "PWD");
	if (!tmp_list)
		ret = add_elist(&env_list, "OLDPWD", tmp_pwd);
	else
		ret = mod_eval((t_env *)tmp_list->data, tmp_pwd);
	tmp_list = get_elist(env_list, "PWD");
	if (!tmp_list)
		ret = add_elist(&env_list, "PWD", getcwd(cwd, BUFFER_SIZE));
	else
		ret = mod_eval((t_env *)tmp_list->data, getcwd(cwd, BUFFER_SIZE));
	return (ret);
}

static void
	print_chdir_error_messages(
	t_list *env_list,
	char *path,
	int flag_print)
{
	if (!get_eval(env_list, "OLDPWD") \
			&& !exact_strncmp(path, "-") && flag_print)
		printf("cd: OLDPWD not set\n");
	else if (!get_eval(env_list, "HOME") && flag_print)
		printf("cd: HOME not set\n");
	else if (flag_print)
		printf("cd: %s: No such file or directory\n", path);
}

int
	sh_bti_cd(
	char **args,
	t_list *env_list,
	int flag_print)
{
	char	*path;
	int		ret;

	ret = 0;
	if (!(path = get_path(args[0], env_list)))
		ret = ERR_CD_ALLOC_FAIL;
	if (!ret && chdir(path) == -1)
	{
		print_chdir_error_messages(env_list, path, flag_print);
		ret = ERR_CD_CHDIR;
	}
	if (!ret)
		ret = renew_pwd(env_list);
	if (ret != ERR_CD_ALLOC_FAIL)
		free(path);
	if (ret)
		ret = 1;
	g_signal = ret;
	return (ret);
}
