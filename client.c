#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h> 
#include <string.h> 

int main(int argc, char *argv[])
{
	int	server_pid;
	char	*str;

	if (argc != 3)
	{
		printf("Numero de argumentos invalidos");
		return (0);
	}
	str = argv[2];
	server_pid = atoi(argv[1]);
	if (server_pid == 0)
	{
		printf("PID del servidor invalido");
		return (0);
	}
	(void) str;
	kill(server_pid, 10);	
}
