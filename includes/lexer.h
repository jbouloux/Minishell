/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:52:50 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:18:11 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft.h"

typedef struct s_lexer	t_lexer;
typedef struct s_type	t_type;

typedef enum	e_type_op
{
	STRING,
	REDIR_ALIAS,
	SEMICOLON,
	HEREDOC,
	APPEND,
	REDIR_LEFT,
	REDIR_RIGHT,
	AND,
	AND_BINARY,
	OR,
	PIPE,
	PARENTH_LEFT,
	PARENTH_RIGHT,
	HOOK_LEFT,
	HOOK_RIGHT,
	BRACE_LEFT,
	BRACE_RIGHT
}				t_type_op;

struct					s_lexer
{
	short	type;
	char	*value;
	t_lexer	*next;
};

struct					s_type
{
	char	*value;
	int		type;
};

t_lexer					*lexer(char *line);
void					fill_lexer(t_lexer **lex, char *line);
void					lex_push(t_lexer **lex, char *value);
void					type_lexer(t_lexer *lex);
int						choose_type(char *value);
void					free_lexer(t_lexer **lex);
#endif
