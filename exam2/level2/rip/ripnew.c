#include <unistd.h>

void	ft_puts(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

int	count_unbalanced(char *s)
{
	int	i;
	int	open;
	int	close;

	i = 0;
	open = 0;
	close = 0;
	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
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

void	rip(char *s, int must_fix, int nfix, int pos)
{
	int		i;
	char	temp;

	if (nfix == must_fix && !count_unbalanced(s))
	{
		ft_puts(s);
		return ;
	}
	i = pos;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == ')')
		{
			temp = s[i];
			s[i] = ' ';
			rip(s, must_fix, nfix + 1, i + 1);
			s[i] = temp;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	must_fix;

	if (ac != 2)
		return (1);
	must_fix = count_unbalanced(av[1]);
	rip(av[1], must_fix, 0, 0);
	return (0);
}
