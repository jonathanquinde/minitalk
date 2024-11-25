#include "header.h"

void    to_binary(int digit, int server_pid);
void    fill_zero(int digit, int server_pid);

int main(int argc, char *argv[])
{
	int	server_pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Numero de argumentos invalidos");
		return (0);
	}
	str = argv[2];
	server_pid = atoi(argv[1]);
	if (server_pid == 0)
	{
		ft_printf("PID del servidor invalido");
		return (0);
	}
	fill_zero((int) *str, server_pid);
	to_binary((int) *str, server_pid);
}

void    fill_zero(int digit, int server_pid)
{
    int number_zero;

    number_zero = 8;
    while (digit != 0)
    {
        digit /= 2;
        number_zero--;
    }
    while (number_zero)
    {
		kill(server_pid, 12);
        number_zero--;
    }
}

void    to_binary(int digit, int server_pid)
{
	if (digit >= 2)
		to_binary(digit/2, server_pid);
	if (digit % 2 == 0)
	{
		kill(server_pid, 12);
	}
	else
	{
		kill(server_pid, 10);
	}
}
