/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:00:12 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:43:16 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*get_cmd(char *name)
{
	char *cmd;

	if (!(cmd = h_get_value_by_key(get_bins(), name)))
	{
		cmd = name;
		if (cmd[0] != '.' && cmd[0] != '/')
		{
			print_error("command not found: ", cmd);
			return (NULL);
		}
		else
		{
			if (check_access(cmd, X_OK))
				return (NULL);
			else
				cmd = ft_strdup(name);
		}
	}
	return (cmd);
}

int				do_exec(char **args, char **env)
{
	int			ret;
	int			father;
	char		*cmd;

	ret = 0;
	if ((ret = run_builtin(args)) != -1)
		return (ret);
	if (!(cmd = get_cmd(args[0])))
		return (-1);
	if ((father = fork()))
	{
		if (father == -1)
			exit_shell("fork error!", 1);
		wait(&ret);
		ft_memdel((void**)&cmd);
	}
	else
	{
		if ((ret = execve(cmd, args, env)))
			exit(ret);
	}
	return (ret);
}
