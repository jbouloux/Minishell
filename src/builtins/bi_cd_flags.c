/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:03:01 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:07:08 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <unistd.h>
#define Q 0
#define S 1
#define L 2
#define P 3
#define NB_FLAGS 4
#define P_FLAG 5
#define CMDPATH args[flags[NB_FLAGS]]

static	int	is_invalid_flags(char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'q' && arg[i] != 's' && arg[i] != 'L' && arg[i] != 'P')
			return (1);
		else
			i++;
	}
	return (0);
}

static int	*get_flags_help(int *flags, int i, char **args)
{
	int j;

	j = 1;
	flags[NB_FLAGS]++;
	while (args[i][j])
	{
		flags[Q] = args[i][j] == 'q' ? 1 : flags[Q];
		flags[S] = args[i][j] == 's' ? 1 : flags[S];
		flags[L] = args[i][j] == 'L' ? 1 : flags[L];
		flags[P] = args[i][j] == 'P' ? 1 : flags[P];
		j++;
	}
	return (flags);
}

int			*bi_cd_get_flags(char **args)
{
	int *flags;
	int	i;

	i = 0;
	if (!(flags = (int *)malloc(sizeof(int) * 6)))
		return (NULL);
	while (i <= 5)
	{
		flags[i] = 0;
		i++;
	}
	i = 0;
	while (args[i] && args[i][0] == '-' && args[i][1])
	{
		if (!is_invalid_flags(args[i]))
			flags = get_flags_help(flags, i, args);
		else
			break ;
		i++;
	}
	return (flags);
}

int			bi_cd_change_dir(char *path, int print_path, char *input)
{
	if (chdir(path) == -1)
	{
		print_error("cd: no such file or directory: ", input);
		return (1);
	}
	if (print_path)
	{
		path = ft_str_replace(path, get_shell()->store[HOMEDIR], "~", 0);
		ft_putendl(path);
	}
	return (0);
}
