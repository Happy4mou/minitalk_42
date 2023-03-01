 NAME = server
NAME_C = client

FLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = minitalk_helpers.c
SRC_S = server.c
SRC_C = client.c

OBJ = $(SRC:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all:    $(NAME) $(NAME_C) 

$(NAME):    $(OBJ) $(OBJ_S)
	cc $(FLAGS) $(OBJ) $(OBJ_S) -o $(NAME)

$(NAME_C):    $(OBJ) $(OBJ_C)
	cc $(FLAGS) $(OBJ) $(OBJ_C) -o $(NAME_C)

clean:    
	$(RM) $(OBJ)  $(OBJ_S) $(OBJ_C) 

fclean:    clean
	$(RM) $(NAME) $(NAME_C) 

re: fclean all