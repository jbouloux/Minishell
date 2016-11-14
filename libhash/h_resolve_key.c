/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_resolve_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:57:24 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:02:06 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

int	h_get_key(int size, char *key)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (key[i])
	{
		if (key[i + 1])
			ret += key[i] * (key[i + 1] * i);
		else
			ret += key[i] * i;
		i++;
	}
	return (ret % size);
}
