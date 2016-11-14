/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:52 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:49:25 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*shell_prompt(t_shell *sh)
{
	char	*buf;
	char	*prompt;

	if (sh->prompt)
		free(sh->prompt);
	buf = sh->store[PWD];
	prompt = ft_strdup("\033[32m");
	prompt = ft_strrejoin(prompt, prompt, sh->store[LOGNAME]);
	prompt = ft_strrejoin(prompt, prompt, "\033[00m => \033[32m");
	prompt = ft_strrejoin(prompt, prompt, buf);
	prompt = ft_strrejoin(prompt, prompt, \
			"\033[32m\n\033[00m\033[36m$> \033[00m");
	return (sh->prompt = prompt);
}
