#include "header.h"

void	handle(int signum, siginfo_t *info, void *ucontext);
void	build_byte(unsigned char bit);
void	putnbr(unsigned int num);
void print_str(t_list *letter);

struct s_message g_message;

int	main(void)
{
	write(1, "PID: ", 5);
	putnbr(getpid());
	write(1, "\n", 1);
	g_message.str = NULL;
	struct sigaction	sa_usr1;
	sigemptyset(&sa_usr1.sa_mask);
	sa_usr1.sa_flags = SA_SIGINFO;
	sa_usr1.sa_sigaction = handle;
	sigaction(10, &sa_usr1, NULL);
	sigaction(12, &sa_usr1, NULL);
	while (1)
	{
		;
	}
}

void	build_byte(unsigned char bit)
{
	static unsigned char ch = 1;
	t_list *new_node;
	
	if (bit == 1)
		ch = ch << 1 | 1;
	else
		ch = ch << 1;
	if (ch == 128)
	{
		print_str(g_message.str);
		g_message.str = NULL;
		ch = 1;
	}
	else if ((ch & 128) == 128)
	{
		new_node = ft_lstnew(malloc(1));
		if (new_node == NULL || new_node->content == NULL)
		{
			ft_lstclear(&g_message.str, free);
			return ;
		}
		*(unsigned char *)new_node->content = ch - 128;
		ft_lstadd_front(&g_message.str, new_node);
		ch = 1;
	}
}

void print_str(t_list *letter)
{
	if (letter->next != NULL)
		print_str(letter->next);
	write(1, letter->content, 1);
	ft_lstdelone(letter, free);
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
