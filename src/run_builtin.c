/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:37 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:47:25 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		run_builtin(char **args)
{
	static t_shell	*sh = NULL;
	int				index;

	if (!sh)
		sh = get_shell();
	if ((index = builtin_index(sh->builtins, args[0])) != -1)
		return (sh->builtins[index].run(sh, args + 1));
	return (-1);
}
