/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:30:09 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 19:36:37 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#define CC t[0]
#define II t[1]
#define EC t[2]

static int		is_double(int type)
{
	return ((type == REDIR_ALIAS || type == HEREDOC
		|| type == APPEND || type == AND || type == OR) ? 1 : 0);
}

static int		is_separator(char c)
{
	return ((c == ' ' || ft_isescaped(c) || choose_type(&c)) ? 1 : 0);
}

static int		is_quote(char c)
{
	return ((c == 39 || c == 34) ? c : 0);
}

static char		escaped_char(char c)
{
	if (c == '\\')
		return ('\\');
	if (c == 'a')
		return ('\a');
	if (c == 'b')
		return ('\b');
	if (c == 'f')
		return ('\f');
	if (c == 'n')
		return ('\n');
	if (c == 'r')
		return ('\r');
	if (c == 't')
		return ('\t');
	if (c == 'v')
		return ('\v');
	return (0);
}

static int		get_value_help(char *temp_ipp, char ec, int ret)
{
	*temp_ipp = ec;
	return (ret);
}

static char		*get_value(char **line)
{
	static char			temp[255];
	int					t[3] = {0, 0, 0};

	ft_bzero(temp, 255);
	while (**line && (CC || (!CC && !is_separator(**line))))
	{
		if (**line == '\\' && *(*line + 1))
		{
			if (CC && (EC = (int)escaped_char(*(*line + 1))))
				*line += get_value_help(&temp[II++], EC, 1);
			else if (!CC && (*(*line + 1) == '\'' || *(*line + 1) == '\"'))
				temp[II++] = *(++*line);
			else if (!CC && *(*line + 1) == '\\' && *(*line + 2) != '\\'
			&& (EC = (int)escaped_char(*(*line + 2))))
				*line += get_value_help(&temp[II++], EC, 2);
			++*line;
			continue ;
		}
		if ((is_quote(**line) && (CC == 0 || CC == **line)) && ((CC = \
		(CC == **line) ? 0 : *((*line)++)) || 1))
			continue ;
		temp[II++] = *((*line)++);
	}
	return (ft_strdup(temp));
}

void			fill_lexer(t_lexer **lex, char *line)
{
	short			type;
	char			buf[2];

	while (line && *line)
	{
		ft_bzero(buf, 2);
		type = choose_type(line);
		if (type)
		{
			ft_memcpy(buf, line, is_double(type) ? 2 : 1);
			lex_push(lex, ft_strdup(buf));
			line += is_double(type) ? 2 : 1;
			continue ;
		}
		if (ft_isescaped(*line) || *line == ' ')
			line++;
		else
			lex_push(lex, get_value(&line));
	}
}
