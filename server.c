#include "header.h"

void	handle(int signum, siginfo_t *info, void *ucontext);
void	build_byte(unsigned char bit);
void	bits_to_char(char byte[8]);
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

void	bits_to_char(char byte[8])
{
	unsigned char	ch;

	ch = 0;
	if (byte[0] == 1)
		ch += 128;
	if (byte[1] == 1)
		ch += 64;
	if (byte[2] == 1)
		ch += 32;
	if (byte[3] == 1)
		ch += 16;
	if (byte[4] == 1)
		ch += 8;
	if (byte[5] == 1)
		ch += 4;
	if (byte[6] == 1)
		ch += 2;
	if (byte[7] == 1)
		ch += 1;
	write(1, &ch, 1);
	if (ch == 0)
		write(1, "\n", 1);
}

void	build_byte(unsigned char bit)
{
	static unsigned char byte[8];
	static unsigned int i;
	
	byte[i] = bit;
	i++;
	if (i == 8)
	{
		i = 0;
		bits_to_char(byte);
	}
}

void	handle(int signum, siginfo_t *info, void *ucontext)
{
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
