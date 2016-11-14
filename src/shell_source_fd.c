/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_source_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:02:05 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:02:07 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_source_fd(t_shell *sh, int fd)
{
	int		first_line;
	int		ret;
	char	*line;

	line = NULL;
	first_line = 1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (exit_shell(ERR_READ, 1));
		if (first_line || ft_strncmp(line, "#!", 2))
			shell_source_line(sh, line);
		first_line = 0;
		ft_memdel((void **)&line);
	}
}
