#include "header.h"

void	handle(int signum, siginfo_t *info, void *ucontext);
void	build_byte(unsigned char bit);
void	putnbr(unsigned int num);
void print_str(void);
void add_space(void);

struct s_message g_message;

int	main(void)
{
	g_message.str = malloc(1);
	if (g_message.str == NULL)
		return (0);
	struct sigaction	sa_usr1;
	sigemptyset(&sa_usr1.sa_mask);
	sa_usr1.sa_flags = SA_SIGINFO;
	sa_usr1.sa_sigaction = handle;
	write(1, "PID: ", 5);
	putnbr(getpid());
	write(1, "\n", 1);
	sigaction(10, &sa_usr1, NULL);
	sigaction(12, &sa_usr1, NULL);
	while (1)
	{
		if (g_message.need_space)
			add_space();
	}
}

void	build_byte(unsigned char bit)
{
	static unsigned char ch = 1;
	
	if (bit == 1)
		ch = ch << 1 | 1;
	else
		ch = ch << 1;
	if ((ch & 128) == 128)
	{
		if (ch == 128)
			print_str();
		else
		{
			g_message.str[g_message.size] = ch - 128;
			g_message.size++;
			g_message.need_space = 1;
		}
		ch = 1;
	}
}

void print_str(void)
{
	write(1, g_message.str, g_message.size);
	free (g_message.str);
	g_message.str = NULL;
	g_message.size = 0;
	g_message.need_space = 1;
}

void add_space(void)
{
	unsigned char *new_str;

	new_str = malloc(g_message.size + 1);
	if (new_str == NULL)
	{
		free (g_message.str);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(new_str, g_message.str, g_message.size);
	free (g_message.str);
	g_message.str = new_str;
	g_message.need_space = 0;
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
