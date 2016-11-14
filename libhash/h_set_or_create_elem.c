/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_set_or_create_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:57:44 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:02:27 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*h_set_or_create_elem(t_hash *hash, char *key, char *value)
{
	t_elem *elem;

	if ((elem = h_get_elem_by_key(hash, key)))
	{
		ft_memdel((void **)&(elem->value));
		elem->value = ft_strdup(value);
	}
	else
		elem = h_add_elem(hash, key, value);
	return (elem);
}
