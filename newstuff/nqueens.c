
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	print_board(int *board, int n)
{
	int	i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i < n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int is_valid(int *board, int row, int col){
	int i = 0;
	while(i < row){
		if(board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
			return(0);
		i++;
	}
	return(1);
}

void nqueen(int n, int *board, int row){
	int col = 0;
	if(row == n){
		print_board(board, n);
		return;
	}
	while (col < n){
		if(is_valid(board, row, col)){
			board[row] = col;
			nqueen(n, board, row + 1);
		}
		col++;
	}
}



int	main(int ac, char **av)
{
	int n;
	if(ac == 2)
		n = atoi(av[1]);
	else{
		printf("\n");
		return(1);
	}
	int *board = malloc(sizeof(int) * n);
	if(!board)
		return(1);
	int i = 0;
	while(i < n){
		board[i] = 0;
		i++;
	}
	nqueen(n, board, 0);
	free(board);
	return(0);
}

// Assignement name : n_queens
// Expected files : *.c *.h
// Allowed functions : atoi, fprintf, write
// -------------------------------------------------------------------------

// Write a program that will print all the solutions to the n queens problem
// for a n given as argument.
// We will not test with negative values.
// The order of the solutions is not important.

// You will display the solutions under the following format :
// <p1> <p2> <p3> ... \n
// where pn are the line index of the queen in each colum starting from 0.

// For example this should work :
// $> ./n_queens 2 | cat -e

// $> ./n_queens 4 | cat -e
// 1 3 0 2$
// 2 0 3 1$

// $> ./n_queens 7 | cat -e
// 0 2 4 6 1 3 5$
// 0 3 6 2 5 1 4$
// etc...
