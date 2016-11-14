/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_add_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:55:52 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:53:51 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*h_add_elem(t_hash *hash, char *key, char *value)
{
	t_elem	*elem;
	int		index;

	hash->nb_elem++;
	index = h_get_key(hash->size, key);
	elem = lst_push_elem(&(hash->hash_tab[index]), \
			ft_strdup(key), ft_strdup(value));
	return (elem);
}
