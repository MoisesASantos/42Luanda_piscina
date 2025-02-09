include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char c)
{
	char	*hex = "0123456789abcdef";

	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_printable(unsigned char c)
{
	if(c >= 32 && c <= 126)
		ft_putchar(c);
	else
		ft_putchar('.');
}

void	ft_print_adress(unsigned long addr)
{
	char	hex[16];
	int		i;

	i = 0;
	while(i < 16)
	{
		hex[15 - i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i++;
	}
	write(1, hex, 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*ptr;
	unsigned int		i;
	unsigned int		j;

	ptr = (unsigned char *)addr;
	if(size == 0)
		return addr;
	i = 0;
	while( i < size)
	{
		ft_puthex((unsigned long)(ptr + i));
		ft_putchar(":");
		j = 0;
		while(j < 16)
		{
			if(i + j < size)
				ft_print_adress(ptr[i + j]);
			else
				write(1, "  ", 2);
			if (j % 2 == 1)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		while(i + j < size && j < 16)
		{
			ft_printable(ptr[i + j]);
			j++;
		}
		ft_putchar('\n');
		i += 16;
	}
}
