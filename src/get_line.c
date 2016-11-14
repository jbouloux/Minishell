/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:00 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:46:19 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

typedef int			(*t_gl_func)(t_shell *sh, char *prompt, char **line);

static int			without_termcaps(char *prompt, char **line)
{
	ft_putstr(prompt);
	return (get_next_line(0, line));
}

int					get_line(char *prompt, char **line)
{
	static t_shell		*sh = NULL;
	static t_gl_func	func = NULL;
	int					ret;

	if (!sh)
		sh = get_shell();
	if ((ret = without_termcaps(prompt, line)))
	{
		if (ret == -1)
			return (-1);
	}
	else
		exit_shell(NULL, 0);
	return (ret);
}
