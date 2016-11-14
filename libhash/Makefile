NAME = libhash.a

SRC = h_create_hash.c \
			h_memory.c h_print.c \
			h_lst_push.c h_lst_new.c \
			h_resolve_key.c \
			h_get_elem_by_key.c \
			h_add_elem.c h_hash_to_tab.c \
			h_split_store_elem.c \
			h_get_value_by_key.c \
			h_set_or_create_elem.c

OBJ = $(subst .c,.o,$(SRC))

INC = -I./includes/ -I../libft/includes
FLAG = -Wall $(INC)

.SILENT:

all: $(NAME)

$(NAME):
	gcc -O2 $(FLAG) -c  $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	rm *.o

clean :
	rm  -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all
