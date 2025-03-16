NAME = solong
SRC_CLIENT=client.c
SRC_SERVER=server.c server_utils.c
OBJ_CLIENT=$(SRC_CLIENT:.c=.o)
OBJ_SERVER=$(SRC_SERVER:.c=.o)

CC=cc
FLAGS= -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): client server

client: $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(LIB) -o $(CLIENT)

server: $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) $(LIB) -o $(SERVER)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re