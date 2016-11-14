/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:03:30 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:22:12 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	add_local_variable(char **args, t_hash *env)
{
	int		val_ret;
	char	*value;

	value = NULL;
	val_ret = 0;
	if (str_is_digit(args[0]))
	{
		ft_putstr_fd("export: not an identifier: ", 2);
		ft_putendl_fd(args[0], 2);
		ft_freetab((void **)args);
		return (2);
	}
	if (args[2])
	{
		value = strtab_to_string_delim(args, 1, "=");
		if (!(h_set_or_create_elem(env, args[0], value)))
			val_ret = 1;
		free(value);
	}
	else if (!(h_set_or_create_elem(env, args[0], args[1] ? args[1] : "")))
		val_ret = 1;
	if (!ft_strcmp(args[0], "PATH"))
		shell_update_bins(get_shell());
	ft_freetab((void **)args);
	return (val_ret);
}

static int	get_name_and_value(char *arg, t_shell *sh)
{
	char	**args;

	if (!arg || !(ft_strchr(arg, '=')))
		return (1);
	args = ft_strsplit(arg, '=');
	return (add_local_variable(args, sh->env));
}

int			bi_export(t_shell *sh, char **args)
{
	int	i;
	int	val_ret;

	i = 0;
	val_ret = 0;
	while (args[i])
	{
		if ((val_ret = get_name_and_value(args[i], sh)))
		{
			if (val_ret == 1)
				ft_putendl_fd("minishell: bad assignment", 2);
			return (1);
		}
		i++;
	}
	sh->env_update = 1;
	return (0);
}
