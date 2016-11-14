/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:03:11 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:15:01 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#define N 0
#define EE 1
#define E 2
#define NB_FLAGS 3

static int	is_invalid_flags(char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n' && arg[i] != 'e' && arg[i] != 'E')
			return (1);
		else
			i++;
	}
	return (0);
}

static int	*get_flags(char **args)
{
	int *flags;
	int	i;
	int j;

	i = 0;
	flags = (int *)ft_memalloc(sizeof(int) * 4);
	while (args[i] && args[i][0] == '-')
	{
		if (!is_invalid_flags(args[i]))
		{
			j = 1;
			flags[NB_FLAGS]++;
			while (args[i][j])
			{
				flags[N] = args[i][j] == 'n' ? 1 : flags[N];
				flags[EE] = args[i][j] == 'e' ? 1 : flags[EE];
				flags[E] = args[i][j] == 'E' ? 1 : flags[E];
				j++;
			}
		}
		else
			break ;
		i++;
	}
	return (flags);
}

int			bi_echo(t_shell *sh, char **args)
{
	char	*str;
	int		*flags;

	flags = get_flags(args);
	str = stringtab_to_string(args, flags[NB_FLAGS]);
	ft_putstr(str);
	free(str);
	if (!flags[N])
		ft_putchar('\n');
	free(flags);
	return (0);
	(void)sh;
}
