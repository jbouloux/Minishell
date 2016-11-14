/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:04:51 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 19:43:59 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "process.h"

static void	free_args(t_arg *arg)
{
	if (!arg)
		return ;
	if (arg->next != NULL)
		free_args(arg->next);
	free(arg);
}

static void	free_redirs(t_redir *redir)
{
	if (!redir)
		return ;
	if (redir->next)
		free_redirs(redir->next);
	free(redir);
}

void		free_process_list(t_process **first)
{
	t_process *tmp;

	if ((tmp = *first))
	{
		if (tmp->next)
			free_process_list(&tmp->next);
		free_args(tmp->args);
		free_redirs(tmp->redirs[0]);
		free_redirs(tmp->redirs[1]);
		free_redirs(tmp->redirs[2]);
		if (tmp->children)
			free_process_list(&tmp->children);
		free(tmp);
		*first = NULL;
	}
}
