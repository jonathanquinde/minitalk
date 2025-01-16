#include "header.h"

void	handle(int signum, siginfo_t *info, void *ucontext);
void	build_byte(unsigned char bit);
void	putnbr(unsigned int num);

int	main(void)
{
	struct sigaction	sa_usr1;
	struct sigaction	sa_usr2;

	sigemptyset(&sa_usr1.sa_mask);
	sigemptyset(&sa_usr2.sa_mask);
	sa_usr1.sa_flags = SA_SIGINFO;
	sa_usr2.sa_flags = SA_SIGINFO;
	sa_usr1.sa_sigaction = handle;
	sa_usr2.sa_sigaction = handle;
	write(1, "PID: ", 5);
	putnbr(getpid());
	write(1, "\n", 1);
	sigaction(10, &sa_usr1, NULL);
	sigaction(12, &sa_usr2, NULL);
	while (1)
	{
		;
	}
}

void	build_byte(unsigned char bit)
{
	static int count;
	static unsigned char ch;
	
	if (bit == 1)
	{
		ch = ch << 1 | 1;
	}
	else
	{
		ch = ch << 1;
	}
	count++;
	if (count == 8)
	{
		count = 0;
	}
}

void	handle(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (signum == 10)
	{
		build_byte(1);
	}
	else
	{
		build_byte(0);
	}
	kill(info->si_pid, 10);
}

void putnbr(unsigned int num)
{
	char ch;

	if (num >= 10) 
		putnbr(num/10);
	ch = num % 10 + 48;
	write(1 , &ch, 1);
}
