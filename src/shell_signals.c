/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:59 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:50:05 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	signal_sigint(int sig)
{
	t_shell	*sh;

	sh = get_shell();
	ft_putendl("");
	ft_putstr(shell_prompt(sh));
}

void		shell_signals(void)
{
	signal(SIGINT, signal_sigint);
	signal(SIGQUIT, SIG_DFL);
}
