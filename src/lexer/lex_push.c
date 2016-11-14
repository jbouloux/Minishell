/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:30:21 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 19:38:18 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdlib.h>

static t_lexer	*lex_new(char *value)
{
	t_lexer *new_elem;

	if (!(new_elem = (t_lexer *)malloc(sizeof(t_lexer))))
		return (NULL);
	new_elem->value = value;
	new_elem->type = 0;
	new_elem->next = NULL;
	return (new_elem);
}

void			lex_push(t_lexer **lex, char *value)
{
	t_lexer *curr_elem;

	if (!*lex)
	{
		*lex = lex_new(value);
		return ;
	}
	curr_elem = *lex;
	while (curr_elem->next)
		curr_elem = curr_elem->next;
	curr_elem->next = lex_new(value);
}
