#include <stdio.h>

int	count_unbalanced(char *str)
{
	int	i;
	int	open;
	int	close;

	i = 0;
	open = 0;
	close = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}

void	rip(char *str, int must_fix, int nfix, int pos)
{
	int	i;
	char temp;

	if (must_fix == nfix && !count_unbalanced(str))
	{
		puts(str);
		return;
	}
	i = pos;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
		{
			temp = str[i];
			str[i] = ' ';
			rip(str, must_fix, nfix + 1, i + 1);
			str[i] = temp;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	must_fix;

	if (argc != 2)
		return (1);
	must_fix = count_unbalanced(argv[1]);
	rip(argv[1], must_fix, 0, 0);
	return (0);
}
