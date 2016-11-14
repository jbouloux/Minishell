/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_get_elem_by_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:56:10 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:55:05 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*h_get_elem_by_key(t_hash *hash, char *key)
{
	t_elem	*curr_elem;
	int		index;

	index = h_get_key(hash->size, key);
	curr_elem = hash->hash_tab[index];
	if (!curr_elem)
		return (NULL);
	while (curr_elem && ft_strncmp(curr_elem->key, key, ft_strlen(key)))
		curr_elem = curr_elem->next;
	if (!curr_elem)
		return (NULL);
	return (curr_elem);
}
