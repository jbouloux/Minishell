/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arg_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:05:16 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:05:17 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "process.h"

void	push_arg_end(t_arg **first_arg, char *value)
{
	t_arg *new;
	t_arg *current;

	if (!(new = (t_arg *)ft_memalloc(sizeof(t_arg))))
		exit_shell(ERR_MALLOC, 1);
	new->value = value;
	if (!(current = *first_arg))
	{
		*first_arg = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}
