/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:02:29 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:51:43 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

static void	interactive(t_shell *sh)
{
	int			ret;
	char		*line;

	line = NULL;
	sh->is_interactive = 1;
	while ((ret = get_line(shell_prompt(sh), &line)) != -1)
	{
		if (!ret)
			ft_putchar('\n');
		if (line && !*line)
			ft_memdel((void **)&line);
		if (!ret || !line)
		{
			line = NULL;
			continue ;
		}
		shell_source_line(sh, line);
		ft_putchar('\n');
		free(line);
	}
	exit_shell(ERR_READ, 1);
}

void		shell_start(t_shell *sh, int ac, char **av)
{
	shell_signals();
	if (ac != 1)
		bi_source(sh, av + 1);
	else
		interactive(sh);
	exit_shell(NULL, 0);
}
