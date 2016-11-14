/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:04:37 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:04:39 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "shell.h"

static void				parse_args(t_process *process, t_lexer **lex)
{
	while (*lex && (*lex)->type == STRING
	&& !((*lex)->next && (*lex)->next->next
	&& str_is_digit((*lex)->value)
	&& ((*lex)->next->type == REDIR_RIGHT
	|| (*lex)->next->type == REDIR_ALIAS)))
	{
		push_arg_end(&process->args, (*lex)->value);
		++process->nb_args;
		*lex = (*lex)->next;
	}
}

static int				parse_childrens(t_process *process, t_lexer **lex)
{
	int type;

	if (!*lex)
		return (1);
	type = (*lex)->type;
	if ((*lex)->next && (type == AND || type == OR))
	{
		process->operator = type;
		(*lex) = (*lex)->next;
		if (!*lex || (*lex)->type != STRING
		|| !(process->children = build_process(lex)))
			return (0);
	}
	return (1);
}

t_process				*build_process(t_lexer **lex)
{
	t_process	*process;
	t_lexer		*last;

	if (!(process = (t_process *)ft_memalloc(sizeof(t_process))))
		exit_shell(ERR_MALLOC, 1);
	while (*lex && (*lex)->type != SEMICOLON)
	{
		last = *lex;
		parse_args(process, lex);
		if (!parse_childrens(process, lex) || last == *lex)
		{
			free_process_list(&process);
			return (NULL);
		}
	}
	return (process);
}
