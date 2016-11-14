/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_update_bins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:02:39 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:52:00 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "shell.h"

static char	*build_full_path(char *dir, char *name)
{
	static char buffer[4096];
	size_t		len_d;
	size_t		len_n;

	len_d = ft_strlen(dir);
	len_n = ft_strlen(name);
	ft_bzero(buffer, len_d + len_n + 2);
	ft_strcat(buffer, dir);
	ft_strcat(buffer + len_d, "/");
	ft_strcat(buffer + len_d + 1, name);
	return ((char *)buffer);
}

static void	add_bins_from_dir(char *dir, t_hash *bins)
{
	DIR				*dirp;
	struct dirent	*entry;
	char			*path;

	if (!(dirp = opendir(dir)))
		return ;
	while ((entry = readdir(dirp)))
	{
		path = build_full_path(dir, entry->d_name);
		if (!access(path, F_OK | X_OK))
			h_set_or_create_elem(bins, entry->d_name, path);
	}
	closedir(dirp);
}

void		shell_update_bins(t_shell *sh)
{
	char	*path;
	char	**tabp;
	int		i;

	i = 0;
	h_free(&sh->bins, 0);
	if (!(path = get_value("PATH")))
		return ;
	if (!(tabp = ft_strsplit(path, ':')))
		ft_errexit(1, "malloc error!");
	while (tabp[i])
		add_bins_from_dir(tabp[i++], sh->bins);
	h_delete_elem(sh->bins, "cd");
	h_delete_elem(sh->bins, "echo");
	ft_memdel((void **)&path);
	ft_free_tab(&tabp);
}
