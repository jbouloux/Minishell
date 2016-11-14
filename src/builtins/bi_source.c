/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:03:50 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:24:04 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		bi_source(t_shell *sh, char **args)
{
	int		fd;
	char	*line;

	if (!*args)
	{
		print_error("source: not enough arguments.", NULL);
		return (-1);
	}
	if (check_access(args[0], R_OK))
		return (-1);
	if ((fd = open(args[0], O_RDONLY)) == -1)
	{
		print_error("source: open error: ", args[0]);
		return (-1);
	}
	shell_source_fd(sh, fd);
	close(fd);
	return (0);
}
