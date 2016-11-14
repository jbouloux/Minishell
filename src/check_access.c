/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:53:55 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 17:54:29 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_access(char *path, int mode)
{
	int ret;

	ret = access(path, F_OK);
	if (ret)
	{
		print_error(ERR_ACC_EXISTS, path);
		return (-1);
	}
	if (!(ret = access(path, mode)))
		return (0);
	if (mode & R_OK)
		print_error(ERR_ACC_READ, path);
	else if (mode & W_OK)
		print_error(ERR_ACC_WRITE, path);
	else
		print_error(ERR_ACC_EXEC, path);
	return (-1);
}
