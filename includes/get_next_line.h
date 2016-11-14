/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jbouloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:15:49 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:16:38 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct	s_fdslot
{
	int				fd;
	char			*buffer;
	char			*head;
	struct s_fdslot *next;
}				t_fdslot;
int				get_next_line(int const fd, char **line);
#endif
