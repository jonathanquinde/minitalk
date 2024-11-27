#include "header.h"

void    to_binary(unsigned char ch, int server_pid);
void    fill_zero(unsigned char ch, int server_pid);
void	send_string(char	*str, int server_pid);

int main(int argc, char *argv[])
{
	int	server_pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Numero de argumentos invalidos");
		return (1);
	}
	str = argv[2];
	server_pid = atoi(argv[1]);
	if (server_pid == 0)
	{
		ft_printf("PID del servidor invalido");
		return (1);
	}
	send_string(str, server_pid);
}

void	send_string(char *str, int server_pid)
{
	while (*str)
	{
		fill_zero(*str, server_pid);
		to_binary(*str, server_pid);
		str++;
	}
	fill_zero(*str, server_pid);
}

void    fill_zero(unsigned char ch, int server_pid)
{
    int number_zero;

    number_zero = 8;
    while (ch != 0)
    {
        ch /= 2;
        number_zero--;
    }
    while (number_zero)
    {
		kill(server_pid, 12);
		usleep(300);
        number_zero--;
    }
}

void    to_binary(unsigned char ch, int server_pid)
{
	if (ch >= 2)
		to_binary(ch/2, server_pid);
	if (ch % 2 == 0)
	{
		kill(server_pid, 12);
		usleep(300);
	}
	else
	{
		kill(server_pid, 10);
		usleep(300);
	}
}
