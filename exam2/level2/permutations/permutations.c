#include <stdio.h>
#include <stdlib.h>

void	swap(char *c, char *b)
{
	char tmp = *c;
	*c = *b;
	*b = tmp;
}

void	ft_sort(char *str)
{
	int	i;
	int	j;
	i = 0;
	j = 0;

	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				swap(str + j, str + i);
			j++;
		}
		i++;
	}
}

void	permutations(char *str, int	pos)
{
	int	i;
	i = pos;

	if (!str[pos])
		puts(str);
	while(i < str[i])
	{
		ft_sort(str + pos);
		swap(str + i, str + pos);
		permutations(str, pos + 1);
		swap(str + i, str + pos);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
		return (1);
	permutations(argv[1], 0);
	return (0);
}