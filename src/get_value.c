/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:13 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:46:41 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_value(char *key)
{
	static t_shell	*sh = NULL;
	char			*value;

	if (!sh)
		sh = get_shell();
	if ((value = h_get_value_by_key(sh->vars, key)))
		return (value);
	if ((value = h_get_value_by_key(sh->env, key)))
		return (value);
	return (NULL);
}
