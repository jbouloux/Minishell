/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_get_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:05:02 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:05:03 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "process.h"

char	**process_get_args(t_process *process)
{
	t_arg	*current;
	char	**args;
	int		nb;
	int		i;

	nb = process->nb_args;
	if (!(args = (char **)ft_memalloc(sizeof(char *) * (nb + 1))))
		exit_shell(ERR_MALLOC, 1);
	current = process->args;
	i = 0;
	while (i < nb)
	{
		args[i++] = current->value;
		current = current->next;
	}
	args[i] = NULL;
	return (args);
}
