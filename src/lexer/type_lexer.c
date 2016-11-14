/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:30:48 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 19:40:32 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		choose_type(char *value)
{
	int				i;
	static t_type	types[16] = {
		{">&", REDIR_ALIAS}, {";", SEMICOLON}, {"<<", HEREDOC}, {">>", APPEND},
		{"<", REDIR_LEFT}, {">", REDIR_RIGHT}, {"&&", AND}, {"&", AND_BINARY},
		{"||", OR}, {"|", PIPE}, {"(", PARENTH_LEFT}, {")", PARENTH_RIGHT},
		{"{", HOOK_LEFT}, {"}", HOOK_RIGHT}, {"[", BRACE_LEFT},
		{"]", BRACE_RIGHT}
	};

	i = 0;
	while (i < 15)
	{
		if (!ft_strncmp(types[i].value, value, ft_strlen(types[i].value)))
			return (types[i].type);
		i++;
	}
	return (0);
}

void	type_lexer(t_lexer *lex)
{
	while (lex)
	{
		lex->type = choose_type(lex->value);
		lex = lex->next;
	}
}
