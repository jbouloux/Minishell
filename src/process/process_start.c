/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:05:09 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:05:11 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "process.h"

int		process_start(t_process *process)
{
	int ret;

	ret = process_exec(process);
	if ((process->operator == OR && ret)
	|| (process->operator == AND && !ret))
		return (process_start(process->children));
	return (ret);
}
