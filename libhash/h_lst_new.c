/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_lst_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:56:41 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:57:43 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*lst_new_elem(char *key, char *value)
{
	t_elem *new_elem;

	if (!(new_elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	new_elem->key = key;
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}
