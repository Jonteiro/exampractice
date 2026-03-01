#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort(char *s)
{
	int	i = 0;
	int	j = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
				swap(s + j, s + i);
			j++;
		}
		i++;
	}
}

void	perm(char *str, int pos)
{
	int i = pos;

	if (!str[pos])
		puts(str);
	while (i < str[i])
	{
		sort(str + pos);
		swap(str + i, str + pos);
		perm(str, pos + 1);
		swap(str + i, str + pos);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
		return (1);
	perm(argv[1], 0);
	return (0);
}

/*
Assignment name : permutations

Expected files : *.c *.h
Allowed functions : puts, malloc, calloc, realloc, free, write
---------------------------------------------------------------

Write a program that will print all the permutations of a string given as argument.

The solutions must be given in alphabetical order.

We will not try your program with strings containing duplicates (eg: 'abccd')

For example this should work:
$> ./permutations a | cat -e
a$
$> ./permutations ab | cat -e
ab$
ba$
$> ./permutations abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$
*/