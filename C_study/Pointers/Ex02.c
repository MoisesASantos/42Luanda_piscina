#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	char nome[10] = "Adolfo";
	char *s;
	while(*s)
		ft_putchar(*s++);
	ft_putchar('\n');
	return (0);
}
