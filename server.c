#include "header.h"

void	handle(int signum);
void	build_byte(int bit);
void	bits_to_char(char byte[8]);

int	main(void)
{
	int 				pid;
	struct sigaction	sa_usr1;
	struct sigaction	sa_usr2;

	sigemptyset(&sa_usr1.sa_mask);
	sigemptyset(&sa_usr2.sa_mask);
	sa_usr1.sa_flags = 0;
	sa_usr2.sa_flags = 0;
	sa_usr1.sa_handler = handle;
	sa_usr2.sa_handler = handle;
	pid = getpid();
	ft_printf("El servidor esta corriendo, PID:%d\n--------------------------\n", pid);
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
	ft_printf("%c", ch);
	if (ch == 0)
		ft_printf("\n");
}

void	build_byte(int bit)
{
	static char byte[8];
	static int	count;
	
	byte[count] = bit;
	count++;
	if (count == 8)
	{
		count = 0;
		bits_to_char(byte);
	}
}

void	handle(int signum)
{
	if (signum == 10)
	{
		build_byte(1);
	}
	else if (signum == 12)
	{
		build_byte(0);
	}
}
