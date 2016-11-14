/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:03:43 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:03:45 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_setenv(t_shell *sh, char **args)
{
	int size;

	if (!args || !*args)
		return (bi_env(sh, args));
	size = ft_tablen(args);
	if (size < 3)
	{
		if (str_is_digit(args[0]))
		{
			ft_putendl_fd("setenv: name can't be an integer", 2);
			return (1);
		}
		else
			h_set_or_create_elem(sh->env, args[0], args[1]);
	}
	else
	{
		ft_putendl_fd("setenv: usage: [name value]", 2);
		return (1);
	}
	if (!ft_strcmp(args[0], "PATH"))
		shell_update_bins(sh);
	sh->env_update = 1;
	return (0);
}
