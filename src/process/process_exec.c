/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:04:56 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:04:57 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
#include "process.h"
#include "get_next_line.h"

int				process_exec(t_process *process)
{
	int		ret;
	char	**args;

	args = process_get_args(process);
	ret = do_exec(args, get_env());
	free(args);
	return (ret);
}
