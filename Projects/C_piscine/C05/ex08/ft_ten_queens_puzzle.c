/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:00:00 by mosantos          #+#    #+#             */
/*   Updated: 2024/11/05 02:30:00 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_solution(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i
			== row - col || board[i]
			+ i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve_puzzle(int *board, int col, int *count)
{
	int	row;

	if (col == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve_puzzle(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	solve_puzzle(board, 0, &count);
	return (count);
}
