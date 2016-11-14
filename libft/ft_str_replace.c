/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:11:46 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:12:42 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strstr_index(const char *s1, const char *s2)
{
	int i;
	int j;

	if (!*s2)
		return (-1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && s1[i + j] == s2[j])
			j++;
		if (!s2[j])
			return (i);
		j = 0;
		i++;
	}
	return (-1);
}

char			*ft_str_replace(char *s1, char *pattern, char *s2, int free_s1)
{
	char	*dest;
	int		offset;

	if ((offset = ft_strstr_index(s1, pattern)) == -1)
		return (s1);
	dest = ft_strsub(s1, 0, offset);
	dest = ft_strrejoin(dest, dest, s2);
	dest = ft_strrejoin(dest, dest, (s1 + offset + ft_strlen(pattern)));
	if (free_s1)
		ft_memdel((void **)&s1);
	return (dest);
}
