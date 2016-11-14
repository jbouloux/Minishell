/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:00:06 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:41:34 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"

static char	*change_variable(t_hash *env, char **value, int i)
{
	static char	buf[1000];
	static char	buf2[100];
	char		*value2;
	int			j;

	j = 0;
	ft_bzero(buf, 1000);
	ft_bzero(buf2, 100);
	ft_strncpy(buf, *value, i);
	i++;
	while (*value && (*value)[i + j] && ft_isalpha((*value)[i + j]))
		j++;
	ft_strncpy(buf2, (*value) + i, j);
	value2 = h_get_value_by_key(env, buf2);
	ft_strcpy(buf + i - 1, value2);
	ft_strcat(buf, *value + i + j);
	ft_memdel((void*)&value2);
	return (*buf ? ft_strdup(buf) : NULL);
}

static void	check_variable(t_hash *env, char **value)
{
	int		i;
	char	*temp;

	i = 0;
	while (value && *value && (*value)[i])
	{
		if ((*value)[i] == '$')
		{
			temp = change_variable(env, value, i);
			ft_memdel((void *)value);
			*value = temp;
			i = 0;
		}
		i++;
	}
}

void		check_string_variable(t_hash *env, t_lexer *lex)
{
	while (lex)
	{
		if (lex->type == STRING)
			check_variable(env, &(lex->value));
		lex = lex->next;
	}
}
