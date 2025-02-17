#include <unistd.h>

void	imprimir(char *tabela)
{
	char	c;
	int		i;

	i = 0;
	while( i < 10)
	{
		c = tabela[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	segura(char *board, int col, int row)
{
	int	i;

	i = 0;
	while(i < col)
	{
		if(board[i] == row || 
			board[i] - i == row - col
			|| board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	resolve(char *board, int col, int *count)
{
	int	row;

	if(col == 10)
	{
		imprimir(board);
		(*count)++;
		return ;
	}
	row = 0;
	while(row < 10)
	{
		if(segura(board, col, row))
		{
			board[col] = row;
			resolve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	resolve(board, 0, &count);
	return (count);
}
