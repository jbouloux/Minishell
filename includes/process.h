/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:52:58 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:21:30 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "libft.h"
# include "lexer.h"

typedef struct s_process	t_process;
typedef struct s_arg		t_arg;
typedef struct s_redir		t_redir;

struct						s_arg
{
	char					*value;
	t_arg					*next;
};

struct						s_redir
{
	int						fd;
	int						type;
	char					*path;
	t_redir					*next;
};

struct						s_process
{
	t_arg					*args;
	int						nb_args;
	int						operator;
	t_redir					*redirs[3];
	t_process				*children;
	t_process				*next;
};

t_process					*build_process_list(t_lexer **lex);
t_process					*build_process(t_lexer **lex);
void						free_process_list(t_process **first);
void						push_arg_end(t_arg **args, char *value);
void						push_redir_front(t_redir **redirs, int type,\
		char *path, int fd);
void						push_redir_end(t_redir **redirs, int type,\
		char *path, int fd);
char						**process_get_args(t_process *process);
int							process_exec(t_process *process);
int							process_start(t_process *process);
int							redir_get_fd(t_redir *redir);

#endif
