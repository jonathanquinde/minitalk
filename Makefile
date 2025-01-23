CLIENT=client
SERVER=server

SRC_CLIENT=client.c
SRC_SERVER=server.c
OBJ_CLIENT=$(SRC_CLIENT:.c=.o)
OBJ_SERVER=$(SRC_SERVER:.c=.o)

CC=cc
FLAGS= -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) -lrt -o $(SERVER)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re