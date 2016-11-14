/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_hash_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:56:29 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:57:12 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

static char	*get_line(t_elem *elem)
{
	static char buffer[500];

	ft_strclr(buffer);
	ft_strcat(buffer, elem->key);
	ft_strcat(ft_strcat(buffer, "="), elem->value);
	return (ft_strdup(buffer));
}

static void	fill_tab(t_hash *hash, char **tab)
{
	int		i;
	int		j;
	t_elem	*elem;

	j = 0;
	i = 0;
	while (i < hash->size)
	{
		if ((elem = hash->hash_tab[i]))
		{
			while (elem)
			{
				tab[j++] = get_line(elem);
				elem = elem->next;
			}
		}
		i++;
	}
}

char		**hash_to_tab(t_hash *hash)
{
	char	**tab;

	if (!(tab = (char **)ft_memalloc(hash->size * sizeof(char *))))
		return (NULL);
	fill_tab(hash, tab);
	return (tab);
}
