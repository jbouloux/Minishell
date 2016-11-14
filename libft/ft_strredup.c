/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strredup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:27:56 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:13:47 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strredup(char *orig, char *str)
{
	char *tmp;

	tmp = ft_strdup(str);
	ft_memdel((void **)&orig);
	return (tmp);
}
