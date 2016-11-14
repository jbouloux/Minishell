/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_split_store_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:57:52 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:02:50 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	h_split_store_elem(t_hash *hash, char *str, char c)
{
	char **tab;

	tab = ft_strsplit(str, c);
	h_add_elem(hash, tab[0], tab[1]);
	ft_free_tab(&tab);
}
