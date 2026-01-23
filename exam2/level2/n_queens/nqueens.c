#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int		is_safe(int *board, int row, int col)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (abs(board[i] - row) == abs(i - col))
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int *board, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(board[i]);
		if (i < n - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	solve_nqueens(int *board, int col, int n)
{
	int row;

	if (col == n)
	{
		print_solution(board, n);
		return;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(board, row, col))
		{
			board[col] = row;
			solve_nqueens(board, col + 1, n);
		}
		row++;
	}
}

int		main(int argc, char **argv)
{
	int n;
	int *board;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	if (n <= 0)
		return (1);
	board = (int *)malloc(sizeof(int) * n);
	if (!board)
		return (1);
	solve_nqueens(board, 0, n);
	free(board);
	return (0);
}
