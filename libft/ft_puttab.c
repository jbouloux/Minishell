/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 00:59:01 by aschafer          #+#    #+#             */
/*   Updated: 2016/11/08 19:39:30 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tbl)
{
	int i;

	i = 0;
	if (!tbl)
	{
		ft_putstr_color("Pointer not allocated or recently free'd", 3);
		return ;
	}
	if (!tbl[i])
		ft_putstr_color("No entries found !", 3);
	while (tbl[i])
	{
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putendl(tbl[i++]);
	}
}
