NAME = minishell

SRC = 	main.c \
		get_shell.c \
		shell_init.c \
		env_init.c \
		env_check.c \
		shell_start.c \
		get_env.c \
		get_bins.c \
		get_line.c \
		exit_shell.c \
		get_value.c \
		check_access.c \
		print_error.c \
		shell_source_fd.c \
		shell_source_line.c \
		shell_update_bins.c \
		shell_prompt.c \
		check_variable.c \
		run_builtin.c \
		shell_signals.c \
		do_exec.c \
		builtins/get_builtins.c \
		builtins/builtin_index.c \
		builtins/bi_exit.c \
		builtins/bi_print_hash.c \
		builtins/bi_setenv.c \
		builtins/bi_unsetenv.c \
		builtins/bi_env.c \
		builtins/bi_export.c \
		builtins/bi_echo.c \
		builtins/bi_cd.c \
		builtins/bi_cd_flags.c \
		builtins/bi_cd_opt.c \
		builtins/bi_source.c \
		builtins/bi_unset.c \
		lexer/lexer.c \
		lexer/fill_lexer.c \
		lexer/lex_push.c \
		lexer/type_lexer.c \
		lexer/free_lexer.c \
		process/build_process_list.c \
		process/build_process.c \
		process/free_process_list.c \
		process/process_exec.c \
		process/process_get_args.c \
		process/process_start.c \
		process/push_arg_end.c \
		utils/clean_path.c \
		utils/stringtab_to_string.c \
		utils/str_is_digit.c \
		utils/get_next_line.c

INCLUDES = -Ilibft/includes -Ilibhash/includes -Iincludes
LIB_FLAGS = -Llibhash -Llibft -lhash -lft
FLAGS = $(INCLUDES)

OBJ_DIR = obj
DIRS = 	$(OBJ_DIR) \
		$(OBJ_DIR)/utils \
		$(OBJ_DIR)/builtins \
		$(OBJ_DIR)/builtins/history \
		$(OBJ_DIR)/lexer \
		$(OBJ_DIR)/process \

SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIRS) $(OBJS)
	@make -C libft
	@make -C libhash
	@gcc $(OBJS) $(FLAGS) $(LIB_FLAGS) -o $(NAME) -Ofast
	@echo "\n✅  MINISHELL BUILT !"

$(DIRS):
	@mkdir  $@

$(OBJ_DIR)/%.o: %.c
	@gcc  $(FLAGS) -c $< -o $@ -g3
	@echo "$(NAME) => \033[33;32m$@\033[33;0m"

clean:
	rm -rf $(DIRS)

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean
	@make -C libhash fclean

re: fclean all
