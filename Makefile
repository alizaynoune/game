NAME = game
FLAGS = -Wall -Werror -Wextra
INC_P = ./include/
SRC_P = ./src/

SRC_F = main.c	\
	result.c
OBJ = $(addprefix $(SRC_P), $(SRC_F))

INC_F = ./include/header.h
all: $(NAME)

$(NAME): $(OBJ) $(INC_F)
	@gcc $(FLAGS) -I $(INC_P) $(OBJ) -o $(NAME)
	@echo "\e[1;32m done\e[1;0m"

clean :
	@rm -f $(NAME)
re : clean all
