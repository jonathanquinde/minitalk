#include "header.h"

void	to_binary(unsigned char ch, int server_pid);
void	send_string(unsigned char *str, int server_pid);
void	handle(int signum);

int g_ack;

int main(int argc, char *argv[])
{
	int	server_pid;
	struct sigaction	sa_usr1;

	sa_usr1.sa_flags = 0;
	sigemptyset(&sa_usr1.sa_mask);
	sa_usr1.sa_handler = handle;
	sigaction(10, &sa_usr1, NULL);

	if (argc != 3)
	{
		write(1, "Numero erroneo de argumentos", 28);
		return (1);
	}
	if (argv[2][0] == '\0')
		return (1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid == 0)
	{
		write(1, "PID del servidor erroneo", 24);
		return (1);
	}
	send_string((unsigned char *) argv[2], server_pid);
}

void	send_string(unsigned char *str, int server_pid)
{
	while (*str)
	{
		to_binary(*str << 1, server_pid);
		str++;
	}
	to_binary(0, server_pid);
}

void to_binary(unsigned char ch, int server_pid)
{
    size_t bits;

    bits = 7;
    while (bits)
    {
		g_ack = 0;
        if ((ch & 128) == 128)
			kill(server_pid, 10);
        else if ((ch & 128) == 0)
			kill(server_pid, 12);
		while (!g_ack)
		{
			;
		}
        ch <<= 1;
        bits--;
    }
}

void	handle(int signum)
{
	if (signum == 10)
	{
		g_ack = 1;
	}
}
