/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_source_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:02:22 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 20:51:00 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "process.h"

static void		exec_list(t_shell *sh, t_process *list)
{
	static char		**env = NULL;
	t_process		*current;

	current = list;
	while (current)
	{
		sh->cmd_ret = process_start(current);
		if (sh->sigint)
		{
			sh->sigint = 0;
			break ;
		}
		current = current->next;
	}
}

void			shell_source_line(t_shell *sh, char *line)
{
	t_lexer		*lex;
	t_lexer		*start;
	t_process	*process_list;

	process_list = NULL;
	if (!(lex = lexer(line)))
		exit_shell("lex error!", 1);
	check_string_variable(sh->env, lex);
	start = lex;
	if ((process_list = build_process_list(&lex)))
		exec_list(sh, process_list);
	else if (lex)
		print_error(ERR_PARSE, lex->value);
	free_lexer(&start);
	free_process_list(&process_list);
}
