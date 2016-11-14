/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_create_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:56:01 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:54:09 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	*create_hash(char *name, int size)
{
	t_hash *new_hash;

	if (name == NULL)
		return (NULL);
	if (!(new_hash = (t_hash *)ft_memalloc(1 * sizeof(t_hash))))
		return (NULL);
	if (!(new_hash->hash_tab = (t_elem **)ft_memalloc(sizeof(t_elem *) * size)))
		return (NULL);
	new_hash->name = name;
	new_hash->size = size;
	new_hash->nb_elem = 0;
	return (new_hash);
}
