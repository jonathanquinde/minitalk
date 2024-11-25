#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	handler(int x);

int	main(void)
{
	int pid;

	signal(10, handler);
	pid = getpid();
	while(1)
	{
		printf("Server is running\nPID:%d\n------------------\n", pid);
		sleep(5);
	}
}

void	handler(int x)
{
	x = 0;
	printf("hola %d\n", x);
}
