/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:22 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 18:01:23 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	main(int ac, char **av, char **env)
{
	t_shell *sh;

	shell_init((sh = get_shell()), env);
	shell_start(sh, ac, av);
	return (0);
}
