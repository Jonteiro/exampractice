#include <unistd.h>

void	swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	sort(char *s, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}

void	reverse(char *s, int start, int end)
{
	while (start < end)
	{
		swap(&s[start], &s[end]);
		start++;
		end--;
	}
}

int	next_perm(char *s, int len)
{
	int	i;
	int	j;

	i = len - 2;
	while (i >= 0 && s[i] >= s[i + 1])
		i--;
	if (i < 0)
		return (0);
	j = len - 1;
	while (s[j] <= s[i])
		j--;
	swap(&s[i], &s[j]);
	reverse(s, i + 1, len - 1);
	return (1);
}

int	main(int ac, char **av)
{
	int	len;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		sort(av[1], len);
		write(1, av[1], len);
		write(1, "\n", 1);
		while (next_perm(av[1], len))
		{
			write(1, av[1], len);
			write(1, "\n", 1);
		}
	}
	return (0);
}
