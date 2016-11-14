/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:03:57 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:23:16 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_unset(t_shell *sh, char **args)
{
	int i;

	i = 0;
	if (!args[0])
	{
		ft_putendl_fd("unset: not enough arguments", 2);
		return (1);
	}
	while (args[i])
	{
		h_delete_elem(sh->env, args[i]);
		if (!ft_strcmp(args[i], "PATH"))
			shell_update_bins(sh);
		i++;
	}
	sh->env_update = 1;
	return (0);
}
