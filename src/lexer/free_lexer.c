/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:30:16 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 19:30:17 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	free_lexer(t_lexer **lex)
{
	t_lexer *lex_next;

	if (lex && *lex)
	{
		lex_next = (*lex)->next;
		ft_memdel((void**)&((*lex)->value));
		ft_memdel((void**)lex);
		if (lex_next)
			free_lexer(&lex_next);
	}
}
