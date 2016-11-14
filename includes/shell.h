/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:53:06 by jbouloux          #+#    #+#             */
/*   Updated: 2016/11/10 21:28:12 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <signal.h>

# define SHELL_H
# define STORE_SIZE 4
# define NB_BUILTINS 12
# define DEFAULT_PATH "/bin:/usr/bin"
# define HELP_FILES "./help/"

/*
** ERRORS MESSAGES
*/

# define ERR_ACC_EXISTS "file does not exists: "
# define ERR_ACC_READ 	"not allowed to read: "
# define ERR_ACC_WRITE 	"not allowed to write: "
# define ERR_ACC_EXEC	"not allowed to execute: "
# define ERR_PARSE		"parse error near -> "
# define ERR_MALLOC		"FATAL malloc error."
# define ERR_READ		"FATAL read error."

# include "libft.h"
# include "libhash.h"
# include "lexer.h"
# include "get_next_line.h"

typedef struct s_shell			t_shell;
typedef struct s_bi_histo		t_bi_histo;
typedef struct s_builtin		t_builtin;
typedef struct s_bi_histo_flags	t_bi_histo_flags;

typedef enum					e_storage_key
{
	HOMEDIR,
	LOGNAME,
	OLDPWD,
	PWD,
}								t_storage_key;

struct							s_shell
{
	char						*store[STORE_SIZE];
	t_builtin					*builtins;
	t_hash						*env;
	t_hash						*vars;
	t_hash						*bins;
	char						*prompt;
	int							cmd_ret;
	int							env_update;
	int							is_interactive;
	int							sigint;
};

struct							s_builtin
{
	char						*key;
	int							(*run)(t_shell *sh, char **args);
};

/*
** SHELL CORE
*/

t_shell			*get_shell(void);
char			**get_env(void);
t_hash			*get_bins(void);
int				do_exec(char **args, char **env);
int				get_line(char *prompt, char **line);
char			*get_value(char *key);
void			exit_shell(char *msg, int code);
void			restore_fds();
int				check_access(char *path, int mode);
void			print_error(char *str, char *item);
int				shell_init(t_shell *sh, char **env);
void			env_init(t_hash **hash_env, char **envp);
void			shell_update_bins(t_shell *sh);
void			env_check(t_hash *hash_env, char **store);
void			shell_start(t_shell *sh, int ac, char **av);
void			shell_source_fd(t_shell *sh, int fd);
void			shell_source_line(t_shell *sh, char *line);
char			*shell_prompt(t_shell *sh);
char			*stringtab_to_string(char **strings, int begin);
void			shell_exec(t_shell *sh);
void			shell_parse_vars(t_shell *sh, char **line);
void			check_string_variable(t_hash *env, t_lexer *lex);
void			shell_signals(void);

/*
** BUILTINS
*/

t_builtin		*get_builtins();
int				builtin_index(t_builtin *builtins, char *key);
int				run_builtin(char **args);
int				bi_exit(t_shell *sh, char **args);
int				bi_print_hash(t_shell *sh, char **args);
int				bi_setenv(t_shell *sh, char **args);
int				bi_unsetenv(t_shell *sh, char **args);
int				bi_env(t_shell *sh, char **args);
int				bi_echo(t_shell *sh, char **args);
int				bi_cd(t_shell *sh, char **args);
int				*bi_cd_get_flags(char **args);
int				bi_cd_change_dir(char *path, int print_path, char *input);
void			bi_cd_symlink(int *flags, char **path, char **to_clear);
int				bi_source(t_shell *sh, char **args);
int				bi_export(t_shell *sh, char **args);
int				bi_unset(t_shell *sh, char **args);

/*
**	UTILS
*/

char			**str_doublesplit(char *str);
char			*clean_path(char *path);
int				str_is_digit(char *str);
char			*strtab_to_string_delim(char **strings, int begin, char *delim);

#endif
