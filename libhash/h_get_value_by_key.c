/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_get_value_by_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:56:19 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 17:56:21 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

char	*h_get_value_by_key(t_hash *hash, char *key)
{
	t_elem *elem;

	if ((elem = h_get_elem_by_key(hash, key)) == NULL)
		return (NULL);
	if (elem->value == NULL)
		return (NULL);
	return (ft_strdup(elem->value));
}
