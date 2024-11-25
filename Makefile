CC=cc
FLAGS=-Wall -Wextra -Werror

all: server client

server: server.c
	$(CC) $(FLAGS) server.c -o server.out
client: client.c
	$(CC) $(FLAGS) client.c -o client.out

clean:
	rm server client

re: clean all