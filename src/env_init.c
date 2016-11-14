/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:00:28 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:43:28 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	env_init(t_hash **hash_env, char **envp)
{
	if (!(*hash_env = create_hash("env", 300)))
		exit_shell("env hash creation error.", 1);
	if (envp != NULL && *envp != NULL)
	{
		while (*envp)
			h_split_store_elem(*hash_env, *(envp++), '=');
	}
}
