#include "header.h"

void	handle_usr1(int signum);
void	handle_usr2(int signum);

int	main(void)
{
	int pid;

	pid = getpid();
	ft_printf("El servidor esta corriendo, PID:%d\n--------------------------\n", pid);
	signal(10, handle_usr1);
	signal(12, handle_usr2);
	while(1)
	{
		;
	}
}

void	handle_usr1(int signum)
{
	(void)signum;
	write(1, "1", 1);
}
void	handle_usr2(int signum)
{
	(void)signum;
	write(1, "0", 1);
}