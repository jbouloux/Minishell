/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:46 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:48:33 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"

static void			store_init(char *store[STORE_SIZE])
{
	char					buffer[4096];
	struct passwd			*pw;

	if (!(pw = getpwuid(getuid())))
		exit_shell("gepwuid error.", 1);
	if (!(store[HOMEDIR] = ft_strdup(pw->pw_dir)))
		exit_shell(ERR_MALLOC, 1);
	if (!(store[LOGNAME] = ft_strdup(pw->pw_name)))
		exit_shell(ERR_MALLOC, 1);
	ft_bzero(buffer, 4096);
	if (!getcwd(buffer, 4096))
		exit_shell("getcwd error.", 1);
	if (!(store[PWD] = ft_str_replace(buffer, store[HOMEDIR], "~", 0)))
		exit_shell(ERR_MALLOC, 1);
	if (!(store[OLDPWD] = ft_strdup(buffer)))
		exit_shell(ERR_MALLOC, 1);
}

int					shell_init(t_shell *sh, char **env)
{
	ft_bzero(sh, sizeof(sh));
	env_init(&sh->env, env);
	store_init(sh->store);
	env_check(sh->env, sh->store);
	if (!(sh->vars = create_hash("local variables", 300)))
		exit_shell("vars hash creation error.", 1);
	if (!(sh->bins = create_hash("binaries", 9000)))
		exit_shell("bins hash creation errors.", 1);
	shell_update_bins(sh);
	sh->builtins = get_builtins();
	return (0);
}
