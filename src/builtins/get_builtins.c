/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:04:23 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:24:33 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_builtin	*get_builtins(void)
{
	static t_builtin builtins[NB_BUILTINS] = {
		{"exit", bi_exit},
		{"print", bi_print_hash},
		{"env", bi_env},
		{"setenv", bi_setenv},
		{"unsetenv", bi_unsetenv},
		{"exit", bi_exit},
		{"setenv", bi_setenv},
		{"cd", bi_cd},
		{"echo", bi_echo},
		{"export", bi_export},
		{"unset", bi_unset},
		{"source", bi_source}
	};

	return ((t_builtin *)builtins);
}
