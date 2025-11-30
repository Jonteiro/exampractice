#include <unistd.h>
#include <stdio.h>

int	par(char *str)
{
	int i = 0;
	int open = 0;
	int close = 0;

	while (str[i] != '\0')
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
	int	i = pos;
	if (must_fix == nfix && !par(str))
	{
		puts(str);
		return;
	}
	while (str[i])
	{
		if (str[i] == '(' || str[i] == ')')
		{
			char temp;
			temp = str[i];
			str[i] = ' ';
			rip(str, must_fix, nfix + 1, i + 1);
			str[i] = temp;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int must_fix = par(argv[1]);
	rip(argv[1], must_fix, 0, 0);
}