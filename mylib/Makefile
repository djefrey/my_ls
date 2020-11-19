##
## EPITECH PROJECT, 2020
## libmy
## File description:
## first makefile
##

LIST_SRC	=	$(wildcard ./my_list/*.c)
NBR_SRC		=	$(wildcard ./my_nbr/*.c)
STR_SRC		=	$(wildcard ./my_str/*.c)
PRINT_SRC	=	$(wildcard ./my_printf/*.c)
INC_DIR		=	../include/
INC_PRINTF	=	./my_printf/include/
CFLAGS		=	-I$(INC_DIR) -I$(INC_PRINTF) -W -Wall
OBJ			=	$(LIST_SRC:.c=.o) $(NBR_SRC:.c=.o) $(STR_SRC:.c=.o) $(PRINT_SRC:.c=.o)
NAME		=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all