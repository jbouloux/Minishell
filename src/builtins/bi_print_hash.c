/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:03:37 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:03:38 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_print_hash(t_shell *sh, char **args)
{
	if (!ft_strcmp(args[0], "env"))
		h_print(sh->env, VAL_OK | NUM_OK | LEN_OK);
	else if (!ft_strcmp(args[0], "bins"))
		h_print(sh->bins, VAL_OK | NUM_OK | LEN_OK);
	else
	{
		ft_putendl("print Illegal option [bins, env]");
		return (1);
	}
	return (0);
}
