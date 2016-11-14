/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_process_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:04:43 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:04:44 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "shell.h"

t_process	*build_process_list(t_lexer **lex)
{
	t_process	*process;

	process = NULL;
	if ((*lex)->type == SEMICOLON)
		*lex = (*lex)->next;
	if (!*lex || (*lex)->type != STRING || !(process = build_process(lex)))
		return (NULL);
	if (*lex && (*lex)->type == SEMICOLON && (*lex)->next)
		if (!(process->next = build_process_list(lex)))
			return (NULL);
	return (process);
}
