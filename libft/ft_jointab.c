/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jointab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:08:16 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:10:10 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_jointab(char **array)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (array[i])
		len += ft_strlen(array[i++]);
	if (!(str = ft_memalloc(sizeof(char *) * len)))
		return (NULL);
	i = 0;
	while (array[i])
		ft_strcat(str, array[i++]);
	return (str);
}
