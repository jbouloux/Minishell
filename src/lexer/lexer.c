/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:30:42 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 19:39:24 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void		print_lexer(t_lexer *lex)
{
	ft_putendl("");
	while (lex)
	{
		ft_putstr("value: ");
		ft_putstr(lex->value);
		ft_putendl("");
		ft_putstr("type: ");
		ft_putnbr(lex->type);
		ft_putendl("");
		ft_putendl("");
		lex = lex->next;
	}
}

t_lexer			*lexer(char *line)
{
	t_lexer *lex;

	lex = NULL;
	fill_lexer(&lex, line);
	type_lexer(lex);
	return (lex);
}
