/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:30 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:01:31 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "colors.h"

void	print_error(char *str, char *item)
{
	ft_putstr_fd(H_RED, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	if (item)
		ft_putstr_fd(item, 2);
	ft_putendl_fd(INIT, 2);
}
