/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:04:05 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:04:06 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_unsetenv(t_shell *sh, char **args)
{
	int	i;

	i = 0;
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
