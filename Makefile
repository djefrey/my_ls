##
## EPITECH PROJECT, 2020
## bsq
## File description:
## makefile
##

MAIN	=	main.c
SRC		=	read_flags.c		\
			read_folders.c		\
			print_folders.c		\
			print_fcts.c		\
			sort_files.c
CFLAGS	+=	-g -W -Wall -I$(INC_DIR)
MAIN_O	=	$(MAIN:.c=.o)
SRC_O	=	$(SRC:.c=.o)
LIB_DIR	=	./mylib
INC_DIR=	./include
NAME	=	my_ls

all: $(NAME)

$(NAME)	:	$(MAIN_O) $(SRC_O)
	make -C $(LIB_DIR)
	gcc -g -o $(NAME)	$(MAIN_O) $(SRC_O) -I$(INC_DIR) -L$(LIB_DIR) -lmy

clean	:
	make -C $(LIB_DIR) clean
	rm -f $(MAIN_O)
	rm -rf $(SRC_O)

fclean	:	clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re	:	fclean all