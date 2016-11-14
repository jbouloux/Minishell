/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:00:35 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:44:08 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#define TRUE 1

void	exit_shell(char *msg, int code)
{
	t_shell *sh;

	sh = get_shell();
	if (sh->prompt)
		free(sh->prompt);
	if (sh->env)
		h_free(&sh->env, TRUE);
	if (sh->vars)
		h_free(&sh->vars, TRUE);
	if (sh->bins)
		h_free(&sh->bins, TRUE);
	if (msg)
		print_error(msg, NULL);
	exit(code);
}
