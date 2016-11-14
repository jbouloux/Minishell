/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:04:13 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:04:15 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	builtin_index(t_builtin *builtins, char *key)
{
	int i;

	i = 0;
	while (i < NB_BUILTINS)
	{
		if (!ft_strcmp(builtins[i].key, key))
			return (i);
		++i;
	}
	return (-1);
}
