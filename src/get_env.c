/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:00:48 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:45:27 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**get_env(void)
{
	static t_shell	*sh = NULL;
	static char		**env = NULL;

	if (!sh)
		sh = get_shell();
	if (env && !sh->env_update)
		return (env);
	if (env)
		ft_free_tab(&env);
	sh->env_update = 0;
	return ((env = hash_to_tab(sh->env)));
}
